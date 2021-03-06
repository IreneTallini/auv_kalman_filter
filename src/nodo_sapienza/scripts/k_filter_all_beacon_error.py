import numpy as np
from numpy.linalg import inv, pinv
import pymap3d as pm
import matplotlib.pyplot as plt

class Filter:

    def __init__(self, vel_std, yaw_std, range_std, init_pos, n_ranges, 
                 threshold, anch_pos, hz_imu, hz_depth, beacon_err, debug=0) :

        ############################## IMU and DEPTH #########################################
        self.Q        = np.diag([yaw_std, vel_std])**2     # Error covariance
        self.state    = np.array([ [init_pos[0]],
                                   [init_pos[1]] ])        # State
        self.P        = np.eye(2)                          # Covariance
        self.dt       = 1/float(hz_imu)                    # Time difference for imu
        self.dt_depth = 1/float(hz_depth)                  # Time difference for depth sensor
        self.v_x      = 0                                  # Velocity along x
        self.v_y      = 0                                  # Velocity along y
        self.v_z      = 0                                  # Velocity along z
        self.depth    = 0                               
        ######################################################################################

        ############################## ATTITUDE #########################################
        self.roll  = 0
        self.pitch = 0 
        self.yaw   = 0
        ######################################################################################

        ############################ RANGE ######################################
        self.n_ranges     = n_ranges
        self.R            = beacon_err*np.eye(threshold*3) # Ranges covariance
        for i in range(1, threshold):
            self.R[threshold * i - 1, threshold * i - 1] = range_std        
        self.ranges       = np.zeros(n_ranges)           # Ranges measurements
        self.anch_pos     = anch_pos                     # Anchors positions
        self.rg_std       = range_std
        self.times_ranges = np.zeros(n_ranges)

        self.threshold = threshold    # How many ranges to use (0 <= threshold <= n_ranges)
        #########################################################################

        ############################ PLOT / DEBUG ###############################
        self.count = 0
        self.debug  = debug

        plt.scatter([self.anch_pos[0,0], self.anch_pos[1,0], self.anch_pos[2,0], self.anch_pos[3,0]], 
            [self.anch_pos[0,1], self.anch_pos[1,1], self.anch_pos[2,1], self.anch_pos[3,1]], c="yellow")
        plt.scatter(self.state[0,0], self.state[1,0], c="red")
        plt.show()

        #########################################################################

    def L(self, yaw) :
        """ Jacobian with respect to the error (e_yaw, e_vel)"""

        jacob = np.array([[-self.dt*self.v_x*np.sin(yaw), self.dt*np.cos(yaw)], 
                          [ self.dt*self.v_x*np.cos(yaw), self.dt*np.sin(yaw)]])
        return jacob
    

    def f(self, yaw) :
        """Returns f(x) and Jacobian of predict step"""
        
        f = self.state + np.array([[self.dt*self.v_x*np.cos(yaw)],
                                   [self.dt*self.v_x*np.sin(yaw)]])

        return f
    

    def H(self, p, ps):
        """ Returns the Jacobian of measure equation"""

        assert p.shape == (3,1), "p shape is {0}, should be {1}".format(p.shape,(3,1) )
        assert ps.shape == (3,self.threshold), "ps shape is {0}, should be {1}".format(ps.shape,(3,self.threshold))

        p = p.T 
        ps = ps.T

        dp = p[:,:2] - ps[:,:2]
        jacob = dp/np.linalg.norm(p-ps, axis=1).reshape(dp.shape[0], 1)
        
        return jacob

    def M(self, p, ps):
        assert p.shape == (3,1), "p shape is {0}, should be {1}".format(p.shape,(3,1) )
        assert ps.shape == (3,self.threshold), "ps shape is {0}, should be {1}".format(ps.shape,(3,self.threshold))
        p  = p.T 
        ps = ps.T

        dp = p[:, :2] - ps[:, :2]
        dp = dp / np.linalg.norm(p - ps, axis=1).reshape(dp.shape[0], 1)
        jacob = np.concatenate((dp, np.ones((ps.shape[0], 1))), axis=1)

        if self.threshold == 1:
            first = np.expand_dims(jacob[0], axis=0)
            new_jacob = first
        elif self.threshold == 2:
            first = np.expand_dims(jacob[0], axis=0)
            second = np.expand_dims(jacob[1], axis=0)
            three_zeros = np.zeros((1, 3))
            new_jacob = np.concatenate(
                (
                    np.concatenate((first, three_zeros), axis=1),
                    np.concatenate((three_zeros, second), axis=1),
                ),
                axis=0,
            )
        elif self.threshold == 3:
            first = np.expand_dims(jacob[0], axis=0)
            second = np.expand_dims(jacob[1], axis=0)
            third = np.expand_dims(jacob[2], axis=0)
            three_zeros = np.zeros((1, 3))
            six_zeros = np.zeros((1, 6))
            new_jacob = np.concatenate(
                (
                    np.concatenate((first, six_zeros), axis=1),
                    np.concatenate((three_zeros, second, three_zeros), axis=1),
                    np.concatenate((six_zeros, third), axis=1),
                ),
                axis=0,
            )
        return new_jacob


    def update(self, anch_id, rg, ts):
        """Update step of the Kalman filter"""
        
        for i, t in enumerate(self.times_ranges):
            if t != 0 and ts - t > 6:
                self.ranges[i] = 0
                self.times_ranges[i] = 0
            
        self.ranges[anch_id-1]   = rg        
        
        not_zero                 = np.count_nonzero(self.ranges)
        if not_zero >= self.threshold:
            self.count += 1
            print("updating with ranges: ", self.count)
            anch_row = np.where(self.ranges != 0 )
            anch_row = list(set(anch_row[0]) )
            sens     = self.anch_pos[anch_row].T
            pos      = np.concatenate((self.state, [[self.depth]]), axis=0)
            
            H        = self.H(pos, sens)
            M        = self.M(pos, sens)
            
            K = np.dot(np.dot(self.P, H.T), \
                    pinv(np.dot(np.dot(H, self.P), H.T) + np.dot(np.dot(M, \
                         self.R), M.T )) )

            y = self.ranges[anch_row] - np.linalg.norm(pos - sens, axis=0)
            y = y.reshape(y.shape[0], 1)

            self.state = self.state + np.dot(K, y)
                
            self.P      =  np.dot(np.eye(2) - np.dot(K, H), self.P)

            self.ranges = np.zeros(self.n_ranges)


    def predict(self, yaw) :
        """Predict step of the Kalman filter"""
        
        F = np.eye(2)
        L = self.L(yaw)

        self.state    = self.f(yaw)

        self.P     = np.dot(np.dot(F, self.P), F.T) + \
                        np.dot(np.dot(L, self.Q), L.T)

