// Generated by gencpp from file medusa_msgs/AttitudeEuler.msg
// DO NOT EDIT!


#ifndef MEDUSA_MSGS_MESSAGE_ATTITUDEEULER_H
#define MEDUSA_MSGS_MESSAGE_ATTITUDEEULER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace medusa_msgs
{
template <class ContainerAllocator>
struct AttitudeEuler_
{
  typedef AttitudeEuler_<ContainerAllocator> Type;

  AttitudeEuler_()
    : roll(0.0)
    , pitch(0.0)
    , yaw(0.0)  {
    }
  AttitudeEuler_(const ContainerAllocator& _alloc)
    : roll(0.0)
    , pitch(0.0)
    , yaw(0.0)  {
  (void)_alloc;
    }



   typedef double _roll_type;
  _roll_type roll;

   typedef double _pitch_type;
  _pitch_type pitch;

   typedef double _yaw_type;
  _yaw_type yaw;





  typedef boost::shared_ptr< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> const> ConstPtr;

}; // struct AttitudeEuler_

typedef ::medusa_msgs::AttitudeEuler_<std::allocator<void> > AttitudeEuler;

typedef boost::shared_ptr< ::medusa_msgs::AttitudeEuler > AttitudeEulerPtr;
typedef boost::shared_ptr< ::medusa_msgs::AttitudeEuler const> AttitudeEulerConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::medusa_msgs::AttitudeEuler_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::medusa_msgs::AttitudeEuler_<ContainerAllocator1> & lhs, const ::medusa_msgs::AttitudeEuler_<ContainerAllocator2> & rhs)
{
  return lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch &&
    lhs.yaw == rhs.yaw;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::medusa_msgs::AttitudeEuler_<ContainerAllocator1> & lhs, const ::medusa_msgs::AttitudeEuler_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace medusa_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eeec8b25a660789a89540dedcb2b06d6";
  }

  static const char* value(const ::medusa_msgs::AttitudeEuler_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeeec8b25a660789aULL;
  static const uint64_t static_value2 = 0x89540dedcb2b06d6ULL;
};

template<class ContainerAllocator>
struct DataType< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
{
  static const char* value()
  {
    return "medusa_msgs/AttitudeEuler";
  }

  static const char* value(const ::medusa_msgs::AttitudeEuler_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 roll\n"
"float64 pitch\n"
"float64 yaw\n"
;
  }

  static const char* value(const ::medusa_msgs::AttitudeEuler_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.roll);
      stream.next(m.pitch);
      stream.next(m.yaw);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AttitudeEuler_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::medusa_msgs::AttitudeEuler_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::medusa_msgs::AttitudeEuler_<ContainerAllocator>& v)
  {
    s << indent << "roll: ";
    Printer<double>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<double>::stream(s, indent + "  ", v.pitch);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MEDUSA_MSGS_MESSAGE_ATTITUDEEULER_H