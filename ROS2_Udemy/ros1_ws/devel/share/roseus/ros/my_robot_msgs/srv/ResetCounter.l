;; Auto-generated. Do not edit!


(when (boundp 'my_robot_msgs::ResetCounter)
  (if (not (find-package "MY_ROBOT_MSGS"))
    (make-package "MY_ROBOT_MSGS"))
  (shadow 'ResetCounter (find-package "MY_ROBOT_MSGS")))
(unless (find-package "MY_ROBOT_MSGS::RESETCOUNTER")
  (make-package "MY_ROBOT_MSGS::RESETCOUNTER"))
(unless (find-package "MY_ROBOT_MSGS::RESETCOUNTERREQUEST")
  (make-package "MY_ROBOT_MSGS::RESETCOUNTERREQUEST"))
(unless (find-package "MY_ROBOT_MSGS::RESETCOUNTERRESPONSE")
  (make-package "MY_ROBOT_MSGS::RESETCOUNTERRESPONSE"))

(in-package "ROS")





(defclass my_robot_msgs::ResetCounterRequest
  :super ros::object
  :slots (_reset_value ))

(defmethod my_robot_msgs::ResetCounterRequest
  (:init
   (&key
    ((:reset_value __reset_value) 0)
    )
   (send-super :init)
   (setq _reset_value (round __reset_value))
   self)
  (:reset_value
   (&optional __reset_value)
   (if __reset_value (setq _reset_value __reset_value)) _reset_value)
  (:serialization-length
   ()
   (+
    ;; int64 _reset_value
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _reset_value
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _reset_value (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _reset_value) (= (length (_reset_value . bv)) 2)) ;; bignum
              (write-long (ash (elt (_reset_value . bv) 0) 0) s)
              (write-long (ash (elt (_reset_value . bv) 1) -1) s))
             ((and (class _reset_value) (= (length (_reset_value . bv)) 1)) ;; big1
              (write-long (elt (_reset_value . bv) 0) s)
              (write-long (if (>= _reset_value 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _reset_value s)(write-long (if (>= _reset_value 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _reset_value
#+(or :alpha :irix6 :x86_64)
      (setf _reset_value (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _reset_value (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass my_robot_msgs::ResetCounterResponse
  :super ros::object
  :slots (_success ))

(defmethod my_robot_msgs::ResetCounterResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass my_robot_msgs::ResetCounter
  :super ros::object
  :slots ())

(setf (get my_robot_msgs::ResetCounter :md5sum-) "3b73bf1f76bcb54818883adc52048556")
(setf (get my_robot_msgs::ResetCounter :datatype-) "my_robot_msgs/ResetCounter")
(setf (get my_robot_msgs::ResetCounter :request) my_robot_msgs::ResetCounterRequest)
(setf (get my_robot_msgs::ResetCounter :response) my_robot_msgs::ResetCounterResponse)

(defmethod my_robot_msgs::ResetCounterRequest
  (:response () (instance my_robot_msgs::ResetCounterResponse :init)))

(setf (get my_robot_msgs::ResetCounterRequest :md5sum-) "3b73bf1f76bcb54818883adc52048556")
(setf (get my_robot_msgs::ResetCounterRequest :datatype-) "my_robot_msgs/ResetCounterRequest")
(setf (get my_robot_msgs::ResetCounterRequest :definition-)
      "int64 reset_value
---
bool success
")

(setf (get my_robot_msgs::ResetCounterResponse :md5sum-) "3b73bf1f76bcb54818883adc52048556")
(setf (get my_robot_msgs::ResetCounterResponse :datatype-) "my_robot_msgs/ResetCounterResponse")
(setf (get my_robot_msgs::ResetCounterResponse :definition-)
      "int64 reset_value
---
bool success
")



(provide :my_robot_msgs/ResetCounter "3b73bf1f76bcb54818883adc52048556")


