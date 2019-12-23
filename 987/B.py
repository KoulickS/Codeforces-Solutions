import math
x,y=map(int,input().split())
if(x**y>y**x):
    print(">")
elif(x**y<y**x):
    print("<")
else:
    print("=")