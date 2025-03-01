n, q = list(map(int, input().split()))
nests = []
pigeon_idx = dict()
big_movs = []
for i in range(n + 1):
    nests.append({i})
    pigeon_idx[i] = i

def take_idx(pig):
    idx = pigeon_idx[pig]
    if pig in nests[idx]:
        return idx
    for mov in big_movs:
        if idx == mov[0]:
            idx = mov[1]
            continue
        if idx == mov[1]:
            idx = mov[0]
    pigeon_idx[pig] = idx
    return idx

for i in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        idx = take_idx(op[1])
        nests[idx].remove(op[1])
        nests[op[2]].add(op[1])
        pigeon_idx[op[1]] = op[2]
    elif op[0] == 2:
        nests[op[1]], nests[op[2]] = nests[op[2]], nests[op[1]]
        big_movs.append([op[1], op[2]])
    else:
        print(take_idx(op[1]))
