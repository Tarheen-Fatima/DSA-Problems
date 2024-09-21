l=[2,3,4,6,1]
n=len(l)
for i in range(n-1):
    flag=0
    for j in range(n-1-i):
        if l[j]>l[j+1]:
            x=l[j]
            l[j]=l[j+1]
            l[j+1]=x
            flag=1
if flag==0:
    print("already sorted")
print(l)
        