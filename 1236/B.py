def powerMod(x,y,p):
    res = 1
    x %= p
    while y > 0:
        if y&1:
            res = (res*x)%p
        y = y>>1
        x = (x*x)%p
    return res

import sys
import math 
n,m=input().split()
p=1000000007
n=int(n)
m=int(m)
print((powerMod(n,m,p)*math.factorial(m))+1)