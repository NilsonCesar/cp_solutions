n, k = map(int, input().split())
a = list(map(int, input().split()))

a += a

for i in range(n):
    l = i 
    r = 2 * n - 1
    ans = 0

    while l <= r:
        # print(a)
        m = (l + r) // 2
        dist = m - i
        # print(dist, l, r, m, ans)
        if (k * dist + a[i] > a[m]):
            ans = m
            r = m - 1
        else:
            l = m + 1

    if ans >= n:
        print(1 + ans % n)
    else:
        print(1 + ans)