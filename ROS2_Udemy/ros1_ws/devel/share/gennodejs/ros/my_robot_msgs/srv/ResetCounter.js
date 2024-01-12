// Auto-generated. Do not edit!

// (in-package my_robot_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ResetCounterRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.reset_value = null;
    }
    else {
      if (initObj.hasOwnProperty('reset_value')) {
        this.reset_value = initObj.reset_value
      }
      else {
        this.reset_value = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ResetCounterRequest
    // Serialize message field [reset_value]
    bufferOffset = _serializer.int64(obj.reset_value, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ResetCounterRequest
    let len;
    let data = new ResetCounterRequest(null);
    // Deserialize message field [reset_value]
    data.reset_value = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'my_robot_msgs/ResetCounterRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '62f1c93d2d90b2a45f39aab680b0301c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 reset_value
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ResetCounterRequest(null);
    if (msg.reset_value !== undefined) {
      resolved.reset_value = msg.reset_value;
    }
    else {
      resolved.reset_value = 0
    }

    return resolved;
    }
};

class ResetCounterResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ResetCounterResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ResetCounterResponse
    let len;
    let data = new ResetCounterResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'my_robot_msgs/ResetCounterResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ResetCounterResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: ResetCounterRequest,
  Response: ResetCounterResponse,
  md5sum() { return '3b73bf1f76bcb54818883adc52048556'; },
  datatype() { return 'my_robot_msgs/ResetCounter'; }
};
