A=[12,3,6,7,1,4]
n=len(A)
for i in range(1,n):
    j=i-1
    x=A[i]
    while(j>-1 and A[j]>x):
        A[j+1]=A[j]
        j=j-1
    A[j+1]=x
print(A)