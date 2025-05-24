from collections import defaultdict

def fat_n(n):
    fats = []
    freq = defaultdict(int)

    while n % 2 == 0:
        if not freq[2]:
            fats.append(2)
        freq[2] += 1
        n //= 2
    
    fat = 3
    while fat ** 2 <= n:
        while n % fat == 0:
            if not freq[fat]:
                fats.append(fat)
            n //= fat
            freq[fat] += 1
        fat += 2
    
    if n > 1:
        fats.append(n)
        freq[n] += 1

    return fats, freq

y, k = map(int, input().split())
fats, freq = fat_n(y)
sum_fats = 0

for fat in fats:
    sum_fats += fat * freq[fat] - freq[fat]

if k == 1:
    print(2)
elif k >= sum_fats:
    print(y * (k - sum_fats) + y)
else:
    temp_acc = 1
    for fat in fats:
        if k >= fat * freq[fat] - freq[fat]:
            k -= fat * freq[fat] - freq[fat]
            temp_acc *= fat ** freq[fat]
        else:
            k -= k // (fat - 1)
            temp_acc *= fat ** (k // (fat - 1))

    print((k + 1) * temp_acc)