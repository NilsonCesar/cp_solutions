def k_carpet(n):
    if n == 0:
        return ['#']
    prev_carpet = k_carpet(n - 1)
    prev_n = len(prev_carpet)
    carpet = [["." for j in range(3 * prev_n)] for i in range(3 * prev_n)]

    for k in range(3):
        for l in range(3):
            if k == 1 and l == 1:
                continue
                
            for i in range(prev_n):
                for j in range(prev_n):
                    carpet[k * prev_n + i][l * prev_n + j] = prev_carpet[i][j]
    return carpet

n = int(input())
carpet = k_carpet(n)
for sub_carpet in carpet:
    print(''.join(sub_carpet))