n, q = map(int, input().split())
s = input()
s_arr = []
for c in s:
    s_arr.append(c)
print(s_arr, str(s_arr))

for i in range(q):
    x, c = input().split()
    s_arr[int(x) - 1] = c
    print(str(s_arr).count("ABC"))