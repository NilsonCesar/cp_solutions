n, m = map(int, input().split())
cnt = [0] * n
ans = m * (m - 1) // 2

for i in range(m):
    a, b = map(int, input().split())
    cnt[(a + b) % n] += 1

for c in cnt:
    ans -= c * (c - 1) // 2

print(ans)