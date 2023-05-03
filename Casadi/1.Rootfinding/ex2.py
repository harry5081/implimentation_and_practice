#! /usr/bin/python3

# Rootfinding using CasADi

import casadi as c
import ex1 as ex1

X = c.MX.sym('X',2)

print(ex1.g(X))
print(ex1.g(X).shape)

J = c.jacobian(ex1.g(X),X)

print(J)
print(type(J))

# 2.
Jf = c.Function('Jf', [X],[c.jacobian(ex1.g(X),X)])
print(Jf)
print(type(Jf))

# print(Jf(ex1.x0))
print("Jacobian at x0: ",Jf([0.8,2]))

# 3.
finite_difference = -c.solve(Jf(ex1.x0),ex1.g(ex1.x0)) 
print("finite_difference at x0: ", finite_difference)

# 4.
x0 = ex1.x0
for i in range(5):
    x0 = -c.solve(Jf(x0),ex1.g(x0))+x0
print(x0)

