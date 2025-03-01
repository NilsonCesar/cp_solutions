n = int(input())
a = list(map(int, input().split()))
ans = 3 * 10 ** 5
last_num_idx = dict()
for i in range(n):
    idx = last_num_idx.get(a[i], -1)
    if idx != -1:
        ans = min(ans, i - idx + 1)
    last_num_idx[a[i]] = i
print(ans if ans != 3 * 10 ** 5 else -1)
