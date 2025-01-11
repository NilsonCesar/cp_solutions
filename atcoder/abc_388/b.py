n, d = map(int, input().split())
T, A = [], []

for i in range(n):
    t, l = map(int, input().split())
    T.append(t)
    A.append(t * l)

for k in range(1, d + 1):
    for i in range(n):
        A[i] += T[i]
    print(max(A))
