q = int(input())
stack = [0] * 100
for i in range(q):
    ops = list(map(int, input().split()))
    if ops[0] == 1:
        stack.append(ops[1])
    else:
        x = stack.pop()
        print(x)
