n, k = map(int, input().split())
g = [set() for _ in range(n)]

for i in range(n - 1):
    u, v = map(int, input().split())
    g[u - 1].add(v - 1)
    g[v - 1].add(u - 1)

v = set([x - 1 for x in map(int, input().split())])
d = [x for x in range(n) if len(g[x]) == 1]

c = 0
for u in d:
    if u not in v:
        tmp = g[u].pop()
        g[tmp].discard(u)
        c += 1
        
        if len(g[tmp]) == 1:
            d.append(tmp)

print(n - c) 