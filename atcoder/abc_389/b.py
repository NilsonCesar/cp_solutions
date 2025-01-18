x = int(input())
n = 1
while x // n != 1:
    x //= n
    n += 1
print(n)
