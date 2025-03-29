n = int(input())
a = input()
b = input()
ans = 0

for i in range(n):
    ans += a[i] != b[i]

print(ans)
