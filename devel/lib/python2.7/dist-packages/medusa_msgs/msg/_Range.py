# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from medusa_msgs/Range.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Range(genpy.Message):
  _md5sum = "7994b469669796bf792ad7e6f0cece00"
  _type = "medusa_msgs/Range"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """#Range between nodes

#RangeGet
uint8 num_nodes #Number of node(s) to which estimate the range
uint8[] node_ids #Id(s) of the target node(s)
float64 freq #Update frequency in Hertz

#Range
uint8 node #Id of the target node
float64 time  	#Estimated travel time to the target node in seconds
float64 bearing #Estimated bearing angle to the target node in degrees
float64 distance
float64 lat_node
float64 lon_node
float64 depth_node"""
  __slots__ = ['num_nodes','node_ids','freq','node','time','bearing','distance','lat_node','lon_node','depth_node']
  _slot_types = ['uint8','uint8[]','float64','uint8','float64','float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       num_nodes,node_ids,freq,node,time,bearing,distance,lat_node,lon_node,depth_node

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Range, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.num_nodes is None:
        self.num_nodes = 0
      if self.node_ids is None:
        self.node_ids = b''
      if self.freq is None:
        self.freq = 0.
      if self.node is None:
        self.node = 0
      if self.time is None:
        self.time = 0.
      if self.bearing is None:
        self.bearing = 0.
      if self.distance is None:
        self.distance = 0.
      if self.lat_node is None:
        self.lat_node = 0.
      if self.lon_node is None:
        self.lon_node = 0.
      if self.depth_node is None:
        self.depth_node = 0.
    else:
      self.num_nodes = 0
      self.node_ids = b''
      self.freq = 0.
      self.node = 0
      self.time = 0.
      self.bearing = 0.
      self.distance = 0.
      self.lat_node = 0.
      self.lon_node = 0.
      self.depth_node = 0.

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
      _x = self.num_nodes
      buff.write(_get_struct_B().pack(_x))
      _x = self.node_ids
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.Struct('<I%sB'%length).pack(length, *_x))
      else:
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_dB6d().pack(_x.freq, _x.node, _x.time, _x.bearing, _x.distance, _x.lat_node, _x.lon_node, _x.depth_node))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 1
      (self.num_nodes,) = _get_struct_B().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.node_ids = str[start:end]
      _x = self
      start = end
      end += 57
      (_x.freq, _x.node, _x.time, _x.bearing, _x.distance, _x.lat_node, _x.lon_node, _x.depth_node,) = _get_struct_dB6d().unpack(str[start:end])
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
      _x = self.num_nodes
      buff.write(_get_struct_B().pack(_x))
      _x = self.node_ids
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.Struct('<I%sB'%length).pack(length, *_x))
      else:
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_dB6d().pack(_x.freq, _x.node, _x.time, _x.bearing, _x.distance, _x.lat_node, _x.lon_node, _x.depth_node))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 1
      (self.num_nodes,) = _get_struct_B().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.node_ids = str[start:end]
      _x = self
      start = end
      end += 57
      (_x.freq, _x.node, _x.time, _x.bearing, _x.distance, _x.lat_node, _x.lon_node, _x.depth_node,) = _get_struct_dB6d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_dB6d = None
def _get_struct_dB6d():
    global _struct_dB6d
    if _struct_dB6d is None:
        _struct_dB6d = struct.Struct("<dB6d")
    return _struct_dB6d
