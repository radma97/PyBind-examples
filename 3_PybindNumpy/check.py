import sumnp
import numpy as np
x=np.array([1.0,2.0,3.0,4.0,5.0])
print(x)

s=sumnp.vecsum3(x)
print(f"sumnp.vecsum3(x)={s}")
s=sumnp.vecsum(x)
print(f"sumnp.vecsum(x)={s}")
s=sumnp.vecsump(x)
print(f"sumnp.vecsump(x)={s}")


from timeit import default_timer as timer
x=np.linspace(0,100,1000000)

t1=timer()
m=1000
for k in range(m):
   s=sumnp.vecsum(x)
t2=timer()
print("vecsum: ", (t2-t1)*1000/m)

t1=timer()
m=1000
for k in range(m):
   s=sumnp.vecsum(x)
t2=timer()
print("vecsump: ", (t2-t1)*1000/m)
