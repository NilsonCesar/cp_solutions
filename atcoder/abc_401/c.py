import sys

n, k = map(int, input().split())
memo = [1] * (n + 1)
memo[k] = k

for i in range(k + 1, n + 1):
    diff = memo[i - k - 1]
    memo[i] = 2 * memo[i - 1] - diff

print(memo[n] % (10 ** 9))