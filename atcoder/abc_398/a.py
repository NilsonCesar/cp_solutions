n = int(input())
ans = ''

if n % 2 == 0:
    ans = '=='
else:
    ans = '='
l = (n - len(ans)) // 2
ans = l * '-' + ans + l * '-'
print(ans)
