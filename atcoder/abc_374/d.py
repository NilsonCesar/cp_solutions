from math import sqrt, pow

ans = 10 ** 10
permutations = []

def make_permutations(l, act_permutation = []):
    if len(act_permutation) == len(l):
        permutations.append(act_permutation)
        return
    for i in l:
        if i not in act_permutation:
            make_permutations(l, act_permutation + [i])

def calcule_distance(a, b, c, d):
    return sqrt(pow(a - c, 2) + pow(b - d, 2))

def calcule_movement_cost(c, dist):
    return dist / c

n, s, t = map(int, input().split())
make_permutations(list(range(n)))
coords = [] 
for i in range(n):
    a, b, c, d = map(int, input().split())
    coords.append([a, b, c, d])

def make_move(x, y, i_line, lines, act_time):
    if i_line == n:
        global ans
        ans = min(ans, act_time)
        return
    points = [[coords[lines[i_line]][0], coords[lines[i_line]][1]], [coords[lines[i_line]][2], coords[lines[i_line]][3]]]

    for i in [0, 1]:
        dist_move_to = calcule_distance(x, y, points[i][0], points[i][1])
        move_to_line_cost = calcule_movement_cost(s, dist_move_to)
        j = int(not i)
        dist_move_in = calcule_distance(points[i][0], points[i][1], points[j][0], points[j][1])
        move_in_line_cost = calcule_movement_cost(t, dist_move_in)
        make_move(points[j][0], points[j][1], i_line + 1, lines, act_time + move_to_line_cost + move_in_line_cost)

for p in permutations:
    make_move(0, 0, 0, p, 0)

print(ans)