// Generated by gencpp from file medusa_msgs/List.msg
// DO NOT EDIT!


#ifndef MEDUSA_MSGS_MESSAGE_LIST_H
#define MEDUSA_MSGS_MESSAGE_LIST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/String.h>

namespace medusa_msgs
{
template <class ContainerAllocator>
struct List_
{
  typedef List_<ContainerAllocator> Type;

  List_()
    : obj_num(0)
    , obj_name()  {
    }
  List_(const ContainerAllocator& _alloc)
    : obj_num(0)
    , obj_name(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _obj_num_type;
  _obj_num_type obj_num;

   typedef std::vector< ::std_msgs::String_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::std_msgs::String_<ContainerAllocator> >::other >  _obj_name_type;
  _obj_name_type obj_name;





  typedef boost::shared_ptr< ::medusa_msgs::List_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::medusa_msgs::List_<ContainerAllocator> const> ConstPtr;

}; // struct List_

typedef ::medusa_msgs::List_<std::allocator<void> > List;

typedef boost::shared_ptr< ::medusa_msgs::List > ListPtr;
typedef boost::shared_ptr< ::medusa_msgs::List const> ListConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::medusa_msgs::List_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::medusa_msgs::List_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::medusa_msgs::List_<ContainerAllocator1> & lhs, const ::medusa_msgs::List_<ContainerAllocator2> & rhs)
{
  return lhs.obj_num == rhs.obj_num &&
    lhs.obj_name == rhs.obj_name;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::medusa_msgs::List_<ContainerAllocator1> & lhs, const ::medusa_msgs::List_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace medusa_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::medusa_msgs::List_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::medusa_msgs::List_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::medusa_msgs::List_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::medusa_msgs::List_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::medusa_msgs::List_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::medusa_msgs::List_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::medusa_msgs::List_<ContainerAllocator> >
{
  static const char* value()
  {
    return "61b929708fa3003d53352792f40a4e8c";
  }

  static const char* value(const ::medusa_msgs::List_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x61b929708fa3003dULL;
  static const uint64_t static_value2 = 0x53352792f40a4e8cULL;
};

template<class ContainerAllocator>
struct DataType< ::medusa_msgs::List_<ContainerAllocator> >
{
  static const char* value()
  {
    return "medusa_msgs/List";
  }

  static const char* value(const ::medusa_msgs::List_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::medusa_msgs::List_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#List\n"
"\n"
"int32 obj_num\n"
"std_msgs/String[] obj_name\n"
"================================================================================\n"
"MSG: std_msgs/String\n"
"string data\n"
;
  }

  static const char* value(const ::medusa_msgs::List_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::medusa_msgs::List_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.obj_num);
      stream.next(m.obj_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct List_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::medusa_msgs::List_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::medusa_msgs::List_<ContainerAllocator>& v)
  {
    s << indent << "obj_num: ";
    Printer<int32_t>::stream(s, indent + "  ", v.obj_num);
    s << indent << "obj_name[]" << std::endl;
    for (size_t i = 0; i < v.obj_name.size(); ++i)
    {
      s << indent << "  obj_name[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "    ", v.obj_name[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MEDUSA_MSGS_MESSAGE_LIST_H
