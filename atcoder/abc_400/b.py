n, m = map(int, input().split())
ans = 0

for i in range(0, m + 1):
    ans += n ** i

if ans <= 10 ** 9:
    print(ans)
else:
    print('inf')
