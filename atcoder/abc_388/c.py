n = int(input())
A = list(map(int, input().split()))

def binary_search(A, k, ans = -1):
    l, r = 0, len(A) - 1

    while(l <= r):
        m = (l + r) // 2
        if A[m] <= k:
            ans = m
            l = m + 1
        else:
            r = m - 1
    return ans

i = n - 1
ans = 0
while i >= 0:
    j = binary_search(A, A[i] // 2)
    if j != -1:
        ans += j + 1
    i -= 1
print(ans)
