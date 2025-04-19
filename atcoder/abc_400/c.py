import math

n = int(input())
ans = 0

for b in range(1, int(1 + (n + 1) ** 0.5)):
    first_time = True
    for a in range(1, int(math.log2(n + 1) + 1)):
        num /= (b ** 2)
        ans += int(math.log2(num))
print(ans)

