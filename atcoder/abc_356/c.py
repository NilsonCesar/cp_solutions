n, m, k = map(int, input().split())

n_keys = [i for i in range(1, n + 1)]

def build_combinations(comb):
    if len(comb) == 0:
        return [[]]
    combination = []
    for num in build_combinations(comb[1:]):
        combination += [num, num + [comb[0]]]
    return combination

combinations = build_combinations(n_keys)
days = []
ans = 0

for i in range(m):
    inp = input().split()
    c = int(inp[0])
    keys = []
    for i in range(1, c + 1):
        keys.append(int(inp[i]))
    result = inp[-1]

    days.append([c, keys, result])

for combination in combinations:
    is_solution = True

    for day in days:
        keys_day = 0

        for key in combination:
            if key in day[1]:
                keys_day += 1
        
        if day[2] == 'o':
            if keys_day < k:
                is_solution = False
        else:
            if keys_day >= k:
                is_solution = False
        
        if not is_solution:
            break
    
    if is_solution:
        ans += 1

print(ans)