#!/usr/bin/env python3
import casadi as ca

### part 1
#1.1
m = 0.04593
g = 9.81
c = 17.5e-5

p = ca.MX.sym('p',2)
v = ca.MX.sym('v',2)

rhs = ca.vertcat(v,-(1/m)*c*ca.norm_2(v)*v)
rhs[3] -= g
f = ca.Function('rhs',[ca.vertcat(p,v)],[rhs])

print(f([0.0,0.0,35.0,30.0]))

#1.2
ode = {'x':ca.vertcat(p,v), 'ode':rhs}
options = dict()
options["tf"] = 1
intg = ca.integrator('intg','cvodes',ode,options)
print(intg)
print(intg(x0=[0.0,0.0,35.0,30.0]))

### part 2
# 2.1
X0 = ca.MX.sym('X0',4)
fly1sec = ca.Function('fly1sec',[X0],[intg(x0=X0)["xf"]])
print(fly1sec([0.0,0.0,35.0,20.0]))
# 2.2
T = ca.MX.sym('T')
rhs_t = ca.vertcat(v,-(1/m)*c*ca.norm_2(v)*v)
rhs_t[3] -= g
rhs_t*=T
ode_T = {'x':ca.vertcat(p,v),'p':T, 'ode':rhs*T}
options = dict()
options["tf"] = 1
intg_t = ca.integrator('intg_t','cvodes',ode_T,options)
fly = ca.Function('fly',[X0,T],[intg_t(x0=X0, p=T)["xf"]])
print("fly 5s",fly([0,0,35,30],5))
print("-----------------------")

# 2.3
v0 = ca.MX.sym('v0')
theta = ca.MX.sym('theta')
end_x = fly(ca.vertcat(0.0 ,0.0, v0*ca.cos(theta*2*3.14/360), v0*ca.sin(theta*2*3.14/360)),T)
shoot =ca.Function('shoot',[v0, theta, T], [end_x])
print(shoot(50, 30, 5))

# 2.4
height = shoot(50, 30, T)[1]
rf = ca.rootfinder('rf','newton',{'x':T,'g':height})
print(rf(x0=10)["x"])

# 2.5
height = shoot(v0, theta, T)[1]
rf_time = ca.rootfinder('rf_time','newton',{'x':T,'g':height, 'p': ca.vertcat(v0,theta)})
horizon = shoot(v0, theta, rf_time(x0=5,p=ca.vertcat(v0,theta))["x"])[0]
shoot_distance = ca.Function('shoot_distance',[v0,theta],[horizon])
# shoot_distance = ca.Function('shoot_distance',[v,theta],rf_distance(x0=0, p=ca.vertcat(v,theta)))
print(shoot_distance(50,30))

### part 3
# 1
nlp=dict()
nlp["x"] = theta
nlp["f"] = shoot_distance(30, theta)*(-1)
solver = ca.nlpsol('solver','ipopt', nlp)
print(solver(x0=45)["x"])

print("-------------------------------")

# 2
state = ca.vertcat(v0, theta)
cov = ca.MX.zeros(2 ,2)
cov[0,0] = 1
cov[1,1] = 1.2**2

nlp=dict()
nlp["x"] = state
nlp["f"] = ca.jacobian(shoot_distance(v0, theta),state) @ cov @ ca.jacobian(shoot_distance(v0, theta),state).T
nlp["g"] = shoot_distance(v0, theta)


opts = {}
opts["print_time"] = True
ipopt_options={}
ipopt_options["max_iter"] = 100
# ipopt_options["print_level"] = 0
ipopt_options["acceptable_tol"] = 1e-8
ipopt_options["acceptable_obj_change_tol"] = 1e-6
opts["ipopt"]=ipopt_options

solver = ca.nlpsol('solver','ipopt',nlp, opts)
print(solver(x0=ca.vertcat(34,57), lbg=80, ubg=80)["x"])
