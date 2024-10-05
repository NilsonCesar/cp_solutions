ans = []

def choose(l, i, a, b):
    if i == len(l):
        ans.append(max(a, b))
    else:
        choose(l, i + 1, a + l[i], b)
        choose(l, i + 1, a, b + l[i])

n = int(input())
k = list(map(int, input().split()))
choose(k, 0, 0, 0)
print(min(ans))