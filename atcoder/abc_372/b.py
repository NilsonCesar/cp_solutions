from math import log

m = int(input())
ans = []

while m != 0:
    power = int(log(m, 3))
    ans += [power]
    m -= 3 ** power
    # if m % 3 != 0:
    #     ans += [0] * (m % 3)
    #     m -= (m % 3)
    # else:
    #     ans += [(log(m, 3))]
    #     m = 0

print(len(ans))
for number in ans:
    print(number, end=' ')
print()