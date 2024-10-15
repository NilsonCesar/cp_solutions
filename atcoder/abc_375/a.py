n = int(input())
s = input()
ans = 0

for i in range(1, n - 1):
    if s[i - 1] == s[i + 1] and s[i - 1] == '#' and s[i] == '.':
        ans += 1
print(ans)