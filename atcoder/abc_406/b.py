n, k = map(int, input().split())
a = list(map(int, input().split()))
d = 1

for num in a:
    d *= num
    d_str = str(d)
    if len(d_str) > k:
        d = 1

print(d)