; Auto-generated. Do not edit!


(cl:in-package my_robot_msgs-srv)


;//! \htmlinclude ResetCounter-request.msg.html

(cl:defclass <ResetCounter-request> (roslisp-msg-protocol:ros-message)
  ((reset_value
    :reader reset_value
    :initarg :reset_value
    :type cl:integer
    :initform 0))
)

(cl:defclass ResetCounter-request (<ResetCounter-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResetCounter-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResetCounter-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_robot_msgs-srv:<ResetCounter-request> is deprecated: use my_robot_msgs-srv:ResetCounter-request instead.")))

(cl:ensure-generic-function 'reset_value-val :lambda-list '(m))
(cl:defmethod reset_value-val ((m <ResetCounter-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_robot_msgs-srv:reset_value-val is deprecated.  Use my_robot_msgs-srv:reset_value instead.")
  (reset_value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResetCounter-request>) ostream)
  "Serializes a message object of type '<ResetCounter-request>"
  (cl:let* ((signed (cl:slot-value msg 'reset_value)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResetCounter-request>) istream)
  "Deserializes a message object of type '<ResetCounter-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'reset_value) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResetCounter-request>)))
  "Returns string type for a service object of type '<ResetCounter-request>"
  "my_robot_msgs/ResetCounterRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetCounter-request)))
  "Returns string type for a service object of type 'ResetCounter-request"
  "my_robot_msgs/ResetCounterRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResetCounter-request>)))
  "Returns md5sum for a message object of type '<ResetCounter-request>"
  "3b73bf1f76bcb54818883adc52048556")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResetCounter-request)))
  "Returns md5sum for a message object of type 'ResetCounter-request"
  "3b73bf1f76bcb54818883adc52048556")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResetCounter-request>)))
  "Returns full string definition for message of type '<ResetCounter-request>"
  (cl:format cl:nil "int64 reset_value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResetCounter-request)))
  "Returns full string definition for message of type 'ResetCounter-request"
  (cl:format cl:nil "int64 reset_value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResetCounter-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResetCounter-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ResetCounter-request
    (cl:cons ':reset_value (reset_value msg))
))
;//! \htmlinclude ResetCounter-response.msg.html

(cl:defclass <ResetCounter-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ResetCounter-response (<ResetCounter-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResetCounter-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResetCounter-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_robot_msgs-srv:<ResetCounter-response> is deprecated: use my_robot_msgs-srv:ResetCounter-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <ResetCounter-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_robot_msgs-srv:success-val is deprecated.  Use my_robot_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResetCounter-response>) ostream)
  "Serializes a message object of type '<ResetCounter-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResetCounter-response>) istream)
  "Deserializes a message object of type '<ResetCounter-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResetCounter-response>)))
  "Returns string type for a service object of type '<ResetCounter-response>"
  "my_robot_msgs/ResetCounterResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetCounter-response)))
  "Returns string type for a service object of type 'ResetCounter-response"
  "my_robot_msgs/ResetCounterResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResetCounter-response>)))
  "Returns md5sum for a message object of type '<ResetCounter-response>"
  "3b73bf1f76bcb54818883adc52048556")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResetCounter-response)))
  "Returns md5sum for a message object of type 'ResetCounter-response"
  "3b73bf1f76bcb54818883adc52048556")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResetCounter-response>)))
  "Returns full string definition for message of type '<ResetCounter-response>"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResetCounter-response)))
  "Returns full string definition for message of type 'ResetCounter-response"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResetCounter-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResetCounter-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ResetCounter-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ResetCounter)))
  'ResetCounter-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ResetCounter)))
  'ResetCounter-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetCounter)))
  "Returns string type for a service object of type '<ResetCounter>"
  "my_robot_msgs/ResetCounter")