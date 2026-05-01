l1 = input().split()
l2 = input()
v = int(input())

s = "".join([x[0] for x in l1])

if v <= 500 and l1[0] == l1[-1]:
    print("BLOQUEADA")
elif v <= 100:
    print("EFETUADA")
elif s != l2:
    print("BLOQUEADA")
elif v % len(l1) != 0:
    print("BLOQUEADA")
else:
    print("EFETUADA")