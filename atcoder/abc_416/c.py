n, k, x = map(int, input().split())

ans = []
s = [''] * n

def f(n, k, a):
    if not k:
        ans.append(a)
        return

    for i in range(n):
        f(n, k - 1, a + s[i])


for i in range(n):
    s[i] = input()

f(n, k, '')

ans.sort()

print(ans[x - 1])