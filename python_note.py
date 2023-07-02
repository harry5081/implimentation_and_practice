f = lambda x, *arge, y, **kwarge: (x, arge, y, kwarge)
f(1, 'a', 'b', y=10, a=10, b=20)

def apply_fn(x, f): 
  return f(x)

apply_lambda_fn(5, exist_f)         # used defined function
apply_lambda_fn(5, lambda x: x**2)  # create a function on a fly

def apply_fn_generic(fn, *arge, **kwarge):
  return fn(*arge, **kwarge)
