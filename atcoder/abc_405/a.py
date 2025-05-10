r, x = map(int, input().split())

if x == 1 and 1600 <= r <= 2999:
    print('Yes')
elif x == 2 and 1200 <= r <= 2399:
    print('Yes')
else:
    print('No')