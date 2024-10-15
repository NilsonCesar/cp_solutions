n = int(input())
ans = 0
X = 0
Y = 0

for i in range(n):
    x, y = map(int, input().split())
    ans += ((X - x) ** 2 + (Y - y) ** 2) ** 0.5
    X = x
    Y = y

ans += (X ** 2 + Y ** 2) ** 0.5

print(ans)