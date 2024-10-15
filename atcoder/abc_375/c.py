import copy

n = int(input())
grid1 = [['.'] * n]
grid2 = [['.'] * n]

for i in range(n):
    line = input()
    row = ['.']
    for c in line:
        row.append(c)
    grid1.append(copy.deepcopy(row))
    grid2.append(copy.deepcopy(row))

for i in range(1, 1 + n // 2):
    for x in range(i, n + 2 - i):
        for y in range(i, n + 2 - i):
            grid2[y][n + 1 - x] = grid1[x][y]
    grid1 = copy.deepcopy(grid2)
    
for line in grid2[1:]:
    for c in line[1:]:
        print(c, end='')
    print()