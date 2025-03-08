n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    count = 0
    e = a[i]
    for j in range(i, n):
        count += e == a[j]
        if e != a[j]:
            break
    if count >= 3:
        print('Yes')
        exit()
print('No')
