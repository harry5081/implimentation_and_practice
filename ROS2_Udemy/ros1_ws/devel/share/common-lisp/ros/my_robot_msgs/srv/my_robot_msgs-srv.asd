
(cl:in-package :asdf)

(defsystem "my_robot_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ResetCounter" :depends-on ("_package_ResetCounter"))
    (:file "_package_ResetCounter" :depends-on ("_package"))
  ))