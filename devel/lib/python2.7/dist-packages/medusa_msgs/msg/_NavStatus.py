# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from medusa_msgs/NavStatus.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy
import medusa_msgs.msg

class NavStatus(genpy.Message):
  _md5sum = "efaabb5a01aa1186aa62d98b6b280789"
  _type = "medusa_msgs/NavStatus"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """#NavStatus Info

medusa_msgs/Position position
medusa_msgs/AttitudeEuler attitude
medusa_msgs/VelocityNED linear_velocity
time timestamp
================================================================================
MSG: medusa_msgs/Position
#Position Info

float64 latitude
float64 longitude
float64 depth
float64 altitude
================================================================================
MSG: medusa_msgs/AttitudeEuler
float64 roll
float64 pitch
float64 yaw
================================================================================
MSG: medusa_msgs/VelocityNED
float64 north_vel
float64 east_vel
float64 down_vel"""
  __slots__ = ['position','attitude','linear_velocity','timestamp']
  _slot_types = ['medusa_msgs/Position','medusa_msgs/AttitudeEuler','medusa_msgs/VelocityNED','time']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       position,attitude,linear_velocity,timestamp

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(NavStatus, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.position is None:
        self.position = medusa_msgs.msg.Position()
      if self.attitude is None:
        self.attitude = medusa_msgs.msg.AttitudeEuler()
      if self.linear_velocity is None:
        self.linear_velocity = medusa_msgs.msg.VelocityNED()
      if self.timestamp is None:
        self.timestamp = genpy.Time()
    else:
      self.position = medusa_msgs.msg.Position()
      self.attitude = medusa_msgs.msg.AttitudeEuler()
      self.linear_velocity = medusa_msgs.msg.VelocityNED()
      self.timestamp = genpy.Time()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_10d2I().pack(_x.position.latitude, _x.position.longitude, _x.position.depth, _x.position.altitude, _x.attitude.roll, _x.attitude.pitch, _x.attitude.yaw, _x.linear_velocity.north_vel, _x.linear_velocity.east_vel, _x.linear_velocity.down_vel, _x.timestamp.secs, _x.timestamp.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.position is None:
        self.position = medusa_msgs.msg.Position()
      if self.attitude is None:
        self.attitude = medusa_msgs.msg.AttitudeEuler()
      if self.linear_velocity is None:
        self.linear_velocity = medusa_msgs.msg.VelocityNED()
      if self.timestamp is None:
        self.timestamp = genpy.Time()
      end = 0
      _x = self
      start = end
      end += 88
      (_x.position.latitude, _x.position.longitude, _x.position.depth, _x.position.altitude, _x.attitude.roll, _x.attitude.pitch, _x.attitude.yaw, _x.linear_velocity.north_vel, _x.linear_velocity.east_vel, _x.linear_velocity.down_vel, _x.timestamp.secs, _x.timestamp.nsecs,) = _get_struct_10d2I().unpack(str[start:end])
      self.timestamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_10d2I().pack(_x.position.latitude, _x.position.longitude, _x.position.depth, _x.position.altitude, _x.attitude.roll, _x.attitude.pitch, _x.attitude.yaw, _x.linear_velocity.north_vel, _x.linear_velocity.east_vel, _x.linear_velocity.down_vel, _x.timestamp.secs, _x.timestamp.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.position is None:
        self.position = medusa_msgs.msg.Position()
      if self.attitude is None:
        self.attitude = medusa_msgs.msg.AttitudeEuler()
      if self.linear_velocity is None:
        self.linear_velocity = medusa_msgs.msg.VelocityNED()
      if self.timestamp is None:
        self.timestamp = genpy.Time()
      end = 0
      _x = self
      start = end
      end += 88
      (_x.position.latitude, _x.position.longitude, _x.position.depth, _x.position.altitude, _x.attitude.roll, _x.attitude.pitch, _x.attitude.yaw, _x.linear_velocity.north_vel, _x.linear_velocity.east_vel, _x.linear_velocity.down_vel, _x.timestamp.secs, _x.timestamp.nsecs,) = _get_struct_10d2I().unpack(str[start:end])
      self.timestamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_10d2I = None
def _get_struct_10d2I():
    global _struct_10d2I
    if _struct_10d2I is None:
        _struct_10d2I = struct.Struct("<10d2I")
    return _struct_10d2I