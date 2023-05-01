#! /usr/bin/python3

import casadi as c
import ex1 as ex1
import ex2 as ex2
options = {'print_iteration': True}
rf = c.rootfinder('rf','newton',{'x': ex2.X,'g': ex1.g(ex2.X)},options)

print(rf)
print(rf(ex1.x0,[]))
print(rf.stats())