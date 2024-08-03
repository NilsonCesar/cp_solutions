n, m = map(int, input().split())
a = list(map(int, input().split()))

if sum(a) <= m:
    print("infinite")
    exit()

def cond(x):
    s = sum(min(x, num) for num in a)
    return s <= m

ok, ng = 0, max(a)
while ok + 1 < ng:
    mid = (ok + ng) // 2
    if(cond(mid)):
        ok = mid
    else:
        ng = mid

print(ok)