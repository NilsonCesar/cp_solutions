n, m = map(int, input().split())
a = list(map(int, input().split()))
dict = {}
ans = 0

for num in a:
    dict[num] = dict.get(num, 0) + 1 

for i in range(1, m + 1):
    if not dict.get(i, 0):
        print(ans)
        exit()

for num in a[::-1]:
    ans += 1
    dict[num] -= 1
    if not dict[num]:
        print(ans)
        break