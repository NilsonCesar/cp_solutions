s = input()
ans = 0
i = 0
while i < len(s):
    if s[i] == '0' and i != len(s) - 1 and s[i + 1] == '0':
        i += 1
    ans += 1
    i += 1
print(ans)
