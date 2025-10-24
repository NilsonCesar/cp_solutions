import math
q = int(input())

while q:
    k = int(input())
    d = 0
    while k - 9 * (10 ** d) * (d + 1) > 0:
        k -= 9 * (10 ** d) * (d + 1)
        d += 1
    n = 10 ** d + (k - 1) // (d + 1)
    print(str(n)[(k % (d + 1)) - 1])
    q -= 1