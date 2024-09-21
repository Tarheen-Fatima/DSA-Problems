A = [12, 3, 6, 7, 1, 4]
n = len(A)

for i in range(n-1):
    k = i
    for j in range(i+1, n):
        if A[j] < A[k]:
            k = j
    A[i], A[k] = A[k], A[i]

print(A)
