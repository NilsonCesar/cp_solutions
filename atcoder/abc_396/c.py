n, m = map(int, input().split())
b = list(map(int, input().split()))
w = list(map(int, input().split()))
b.sort()
w.sort()
b, w = b[::-1], w[::-1]

ans, i, j = 0, 0, 0

while i < min(n, m) and j < min(n, m):
    if b[i] + w[j] > b[i] and b[i] + w[j] > 0:
        ans += b[i] + w[j]
        j += 1
    elif b[i] > 0:
        ans += b[i]
    i += 1

if n > m:
    while i < n:
        if b[i] > 0:
            ans += b[i]
        i += 1

print(ans)
