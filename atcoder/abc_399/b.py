import copy

n = int(input())
p = list(map(int, input().split()))
p_s = copy.deepcopy(p)
p_s.sort()

r = 1
rank = [0] * n
act_max = n - 1

for i in range(n):
    if act_max < 0:
        break

    x = p_s[act_max]
    act_max -= 1

    while act_max >= 0 and p_s[act_max] == x:
        act_max -= 1

    k = 0
    for j in range(n):
        if p[j] == x:
            rank[j] = r
            k += 1

    r += k

for i in range(n):
    print(rank[i])
