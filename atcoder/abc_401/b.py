n = int(input())
login = False
ans = 0

for i in range(n):
    s = input()
    if s == 'private' and not login:
        ans += 1
    if s == 'login':
        login = True
    if s == 'logout':
        login = False

print(ans)