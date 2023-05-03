#! /usr/bin/python3

import casadi as c

x = c.MX.sym("x")
y = c.MX.sym("y")

p = c.MX.sym("p",2)
A = c.MX.sym("A",4, 5)

f = c.Function("f",[x,y],[c.sin(x)*y])
g = c.Function("g",[x],[c.sqrt(x),x**2])
# h = c.Function("h",[x],[c.sin(x)*y])
F = lambda x,y: c.sin(x)*y

print(type(5))
print(type(5+x))
print(type(x-x))
print((5+x))
print((x-x))

print("------------ equality --------")

print(type(x==x))
print(type(x==y))

print("------------ matrix --------")
print(type(A*x))
print(type(A*0))

print("------------ builtin f --------")
print(type(c.gradient(c.sin(x),x)))
print(type(c.gradient(x,x)))

print("------------ indexing --------")
print(type(p[1]))
print(type(A[:,0]))

print("------------ Function f --------")
print(type(f(1,2)))
print(type(f(1,y)))
print(type(f))
print(type(f.expand()))

print("------------ Function g --------")
print(type(g(9)))
print(type(g(9)[0]))
print(type(g(x)))
print(type(g(x)[0]))
print(type(g(x)[0][0]))

print("------------ Function h --------")
# print(type(h(x)))

print("------------ Function F --------")
print(type(F))
print(type(F(x,y)))
print(type(F(1,2)))

print(p[-1])