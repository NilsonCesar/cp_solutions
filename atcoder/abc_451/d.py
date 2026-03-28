power_2 = []

i = 1

while (i < 1e9):
    power_2.append(str(i))
    i *= 2

ans = set()

def build(p):
    if p != '' and int(p) > 1e9:
        return
    if p != '':
        ans.add(int(p))
    for power in power_2:
        build(p + str(power))

build('')
ans_list = sorted(list(ans))

n = int(input())
print(ans_list[n - 1])