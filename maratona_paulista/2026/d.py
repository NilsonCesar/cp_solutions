n = int(input())

print(" " * n + "_" * (n + 1))

cnt = n + 1
for i in range(n - 1, -1, -1):
    if i == 0:
        print(" " * i + "/" + "_" * n + " " * (cnt - n) + "\\" + "_" * (n + 1))
    else:
        print(" " * i + "/" + " " * cnt + '\\')
        cnt += 2

sp = n + 1
for i in range(n):
    if i == n - 1:
        print(" " * sp + "\\" + "_" * cnt + "/")
    else:
        print(" " * sp + "\\" + " " * cnt + "/")
        cnt -= 2
        sp += 1