n, k = map(int, input().split())

time = [0] * (k + 1)
qtd = [0] * (k + 1)
solve = [False] * (k + 1)

for i in range(n):
    p, t, s = map(int, input().split())

    if not solve[p] and s == 1:
        solve[p] = True
        time[p] = t
    elif not solve[p]:
        qtd[p] += 1

ans = 0
count = 0

for i in range(1, k + 1):
    if (solve[i]):
        count += 1
        ans += qtd[i] * 20 + time[i]

print(count, ans)