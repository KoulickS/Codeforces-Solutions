def getSum(n): 
    sum = 0
    while (n != 0): 
        sum = sum + int(n % 10) 
        n = int(n/10) 
      
    return sum
    
m,s=map(int,input().split())
x=10**(m-1)
#print(x)
y=10**m
a=0 
b=0
flag=0 
flag1=0 
for i in range(x,y):
    if(getSum(i)==s):
        a=i 
        flag=1 
        break
for i in range(y-1,x-1,-1):
    #print(i)
    if(getSum(i)==s):
        b=i 
        flag1=1 
        break 
if(flag1==1 and flag==1):
    print(a,b)
else:
    print(-1,-1)