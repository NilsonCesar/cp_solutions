def f(x):
    sum = 0
    for d in x:
        sum += int(d)
    return sum

n = int(input())

A = [1]

count = 2

for i in range(1, n + 1):
    sum = 0
    for j in range(0, i):
        sum += f(str(A[j]))
    A.append(sum)

print(A[n])