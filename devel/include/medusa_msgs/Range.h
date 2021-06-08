// Generated by gencpp from file medusa_msgs/Range.msg
// DO NOT EDIT!


#ifndef MEDUSA_MSGS_MESSAGE_RANGE_H
#define MEDUSA_MSGS_MESSAGE_RANGE_H


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
struct Range_
{
  typedef Range_<ContainerAllocator> Type;

  Range_()
    : num_nodes(0)
    , node_ids()
    , freq(0.0)
    , node(0)
    , time(0.0)
    , bearing(0.0)
    , distance(0.0)
    , lat_node(0.0)
    , lon_node(0.0)
    , depth_node(0.0)  {
    }
  Range_(const ContainerAllocator& _alloc)
    : num_nodes(0)
    , node_ids(_alloc)
    , freq(0.0)
    , node(0)
    , time(0.0)
    , bearing(0.0)
    , distance(0.0)
    , lat_node(0.0)
    , lon_node(0.0)
    , depth_node(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _num_nodes_type;
  _num_nodes_type num_nodes;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _node_ids_type;
  _node_ids_type node_ids;

   typedef double _freq_type;
  _freq_type freq;

   typedef uint8_t _node_type;
  _node_type node;

   typedef double _time_type;
  _time_type time;

   typedef double _bearing_type;
  _bearing_type bearing;

   typedef double _distance_type;
  _distance_type distance;

   typedef double _lat_node_type;
  _lat_node_type lat_node;

   typedef double _lon_node_type;
  _lon_node_type lon_node;

   typedef double _depth_node_type;
  _depth_node_type depth_node;





  typedef boost::shared_ptr< ::medusa_msgs::Range_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::medusa_msgs::Range_<ContainerAllocator> const> ConstPtr;

}; // struct Range_

typedef ::medusa_msgs::Range_<std::allocator<void> > Range;

typedef boost::shared_ptr< ::medusa_msgs::Range > RangePtr;
typedef boost::shared_ptr< ::medusa_msgs::Range const> RangeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::medusa_msgs::Range_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::medusa_msgs::Range_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::medusa_msgs::Range_<ContainerAllocator1> & lhs, const ::medusa_msgs::Range_<ContainerAllocator2> & rhs)
{
  return lhs.num_nodes == rhs.num_nodes &&
    lhs.node_ids == rhs.node_ids &&
    lhs.freq == rhs.freq &&
    lhs.node == rhs.node &&
    lhs.time == rhs.time &&
    lhs.bearing == rhs.bearing &&
    lhs.distance == rhs.distance &&
    lhs.lat_node == rhs.lat_node &&
    lhs.lon_node == rhs.lon_node &&
    lhs.depth_node == rhs.depth_node;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::medusa_msgs::Range_<ContainerAllocator1> & lhs, const ::medusa_msgs::Range_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace medusa_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::medusa_msgs::Range_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::medusa_msgs::Range_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::medusa_msgs::Range_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::medusa_msgs::Range_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::medusa_msgs::Range_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::medusa_msgs::Range_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::medusa_msgs::Range_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7994b469669796bf792ad7e6f0cece00";
  }

  static const char* value(const ::medusa_msgs::Range_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7994b469669796bfULL;
  static const uint64_t static_value2 = 0x792ad7e6f0cece00ULL;
};

template<class ContainerAllocator>
struct DataType< ::medusa_msgs::Range_<ContainerAllocator> >
{
  static const char* value()
  {
    return "medusa_msgs/Range";
  }

  static const char* value(const ::medusa_msgs::Range_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::medusa_msgs::Range_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#Range between nodes\n"
"\n"
"#RangeGet\n"
"uint8 num_nodes #Number of node(s) to which estimate the range\n"
"uint8[] node_ids #Id(s) of the target node(s)\n"
"float64 freq #Update frequency in Hertz\n"
"\n"
"#Range\n"
"uint8 node #Id of the target node\n"
"float64 time  	#Estimated travel time to the target node in seconds\n"
"float64 bearing #Estimated bearing angle to the target node in degrees\n"
"float64 distance\n"
"float64 lat_node\n"
"float64 lon_node\n"
"float64 depth_node\n"
;
  }

  static const char* value(const ::medusa_msgs::Range_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::medusa_msgs::Range_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num_nodes);
      stream.next(m.node_ids);
      stream.next(m.freq);
      stream.next(m.node);
      stream.next(m.time);
      stream.next(m.bearing);
      stream.next(m.distance);
      stream.next(m.lat_node);
      stream.next(m.lon_node);
      stream.next(m.depth_node);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Range_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::medusa_msgs::Range_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::medusa_msgs::Range_<ContainerAllocator>& v)
  {
    s << indent << "num_nodes: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.num_nodes);
    s << indent << "node_ids[]" << std::endl;
    for (size_t i = 0; i < v.node_ids.size(); ++i)
    {
      s << indent << "  node_ids[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.node_ids[i]);
    }
    s << indent << "freq: ";
    Printer<double>::stream(s, indent + "  ", v.freq);
    s << indent << "node: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.node);
    s << indent << "time: ";
    Printer<double>::stream(s, indent + "  ", v.time);
    s << indent << "bearing: ";
    Printer<double>::stream(s, indent + "  ", v.bearing);
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
    s << indent << "lat_node: ";
    Printer<double>::stream(s, indent + "  ", v.lat_node);
    s << indent << "lon_node: ";
    Printer<double>::stream(s, indent + "  ", v.lon_node);
    s << indent << "depth_node: ";
    Printer<double>::stream(s, indent + "  ", v.depth_node);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MEDUSA_MSGS_MESSAGE_RANGE_H
