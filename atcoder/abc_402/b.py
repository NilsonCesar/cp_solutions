q = int(input())
queue = []
i = 0

while q:
    ops = list(map(int, input().split()))
    if ops[0] == 1:
        queue.append(ops[1])
    else:
        print(queue[i])
        i += 1
    q -= 1