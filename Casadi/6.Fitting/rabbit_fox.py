#!/usr/bin/env python3
import numpy as np

p = np.array([1.43, 0.99, 0.22, 0.022, 0.022, 0.011])
step = 10
x0, y0 = 10, 0.1
init = np.array([x0,y0])
record = np.empty((2,step+1))
record[:,0] = init
np.set_printoptions(precision=2, suppress=True)

for i in range(step):
    record[0, i+1] = (p[0]*record[0, i] - p[2]*record[0, i]*record[1, i])/(1+p[4]*record[0, i])
    record[1, i+1] = (p[1]*record[1, i] + p[3]*record[0, i]*record[1, i])/(1+p[5]*record[1, i])
print(record)

data = np.loadtxt('data.mat')
print(data)
error_sum=0
for i in range(step+1):
    real_data = data[i]
    model_data = record[:,i]
    sqr_error = (real_data[0]-model_data[0])**2 + (real_data[1]-model_data[1])**2
    error_sum += sqr_error
print(error_sum)