#!/usr/bin/env python3
import casadi as ca

### part 1
m = 0.04593
g = 9.81
c = 17.5e-5

p = ca.MX.sym('p',2)
v = ca.MX.sym('v',2)

rhs = ca.vertcat(v,-(1/m)*c*ca.norm_2(v)*v)
rhs[3] -= g
f = ca.Function('rhs',[ca.vertcat(p,v)],[rhs])

print(f([0.0,0.0,35.0,30.0]))

### part 2
ode = {'x':ca.vertcat(p,v), 'ode':rhs}
options = dict()
options["tf"] = 1
intg = ca.integrator('intg','cvodes',ode,options)
print(intg)
print(intg(x0=[0.0,0.0,35.0,30.0]))

### part 3
# 3.1
X0 = ca.MX.sym('X0',4)
fly1sec = ca.Function('fly1sec',[X0],[intg(x0=X0)["xf"]])
print(fly1sec([0.0,0.0,35.0,20.0]))
# 3.2
T = ca.MX.sym('T')
rhs_t = ca.vertcat(v,-(1/m)*c*ca.norm_2(v)*v)
rhs_t[3] -= g
rhs_t*=T
ode_T = {'x':ca.vertcat(p,v),'p':T, 'ode':rhs*T}
options = dict()
options["tf"] = 1
intg_t = ca.integrator('intg_t','cvodes',ode_T,options)
fly = ca.Function('fly',[X0,T],[intg_t(x0=X0, p=T)["xf"]])
print("fly 5s",fly([0.0,0.0,35.0,30.0],5))
