c1 = int(input())
c2 = int(input())
c3 = int(input())

if c1<c2<c3:
    print(1)
elif(c1+c2) < c3:
    print(1)
elif c1<c2 or c1<c3:
    print(2)
else:
    print(3)