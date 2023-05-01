#! /usr/bin/python3

# Finite-difference

# from casadi import *
import casadi as c

def g(w):
    x = w[0]
    y = w[1]
    g1 = c.tanh((x+2)*y**2/25-0.5)
    g2 = c.sin(x)- 0.5*y + 1
    return c.vertcat(g1, g2)

########################################
# Jacobian
epsilon = 1e-8
x1 = -0.8
x2 = 2
x0 = c.vertcat(x1,x2)

s_scale = 10
s = [c.vertcat(s_scale,0),c.vertcat(0,s_scale)]

def j_g(x0):
    return  c.vertcat(c.horzcat(((g(x0+s[0]*epsilon) - g(x0))/epsilon/s_scale)[0],
                                        ((g(x0+s[1]*epsilon) - g(x0))/epsilon/s_scale)[0])
                                ,c.horzcat(((g(x0+s[0]*epsilon) - g(x0))/epsilon/s_scale)[1],
                                        ((g(x0+s[1]*epsilon) - g(x0))/epsilon/s_scale)[1]))


if __name__ == '__main__':
    print(g(c.vertcat(-0.8,2)))
    print(g(c.vertcat(-0.8,2)).shape)

    ########################################
    # Jacobian
    print("Jacobian: ",j_g(x0))

    #################################################
    # Newton step
    I = c.horzcat(c.vertcat(1,0),c.vertcat(0,1))

    iter_x0 = [x0]
    for i in range(5):
        g_inverse = c.solve(j_g(iter_x0[i]),I)
        new_x0 = iter_x0[i]- c.mtimes(g_inverse,g(iter_x0[i]))
        iter_x0.append(new_x0)
    print("Newton step: ", iter_x0)
