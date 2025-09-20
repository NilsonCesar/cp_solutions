def solve():
    h, w = map(int, input().split())
    grid = [input() for _ in range(h)]
    inf = float('inf')
    dp = [[inf] * (1 << w) for _ in range(h)]
    mask_0 = 0
    for j in range(w):
        if grid[0][j] == '#':
            mask_0 |= (1 << j)
    
    for mask in range(1 << w):
        cost = 0
        pos = True

        for j in range(w):
            bit_i = (mask_0 >> j) & 1
            bit_f = (mask >> j) & 1

            if bit_f == 1 and bit_i == 0:
                pos = False
                break
            
            if bit_f == 0 and bit_i == 1:
                cost += 1
        
        if pos:
            dp[0][mask] = cost

    for i in range(1, h):
        mask_0 = 0
        for j in range(w):
            if grid[i][j] == '#':
                mask_0 |= (1 << j)
        
        for mask in range(1 << w):
            cost = 0
            pos = True

            for j in range(w):
                bit_i = (mask_0 >> j) & 1
                bit_f = (mask >> j) & 1

                if bit_f == 1 and bit_i == 0:
                    pos = False
                    break
                elif bit_i + bit_f == 1:
                    cost += 1
            
            if not pos:
                continue

            min_prev_cost = inf
            for prev_mask in range(1 << w):
                if dp[i - 1][prev_mask] == inf:
                    continue

                valid = True

                for j in range(w - 1):
                    prev_tiles_black = ((prev_mask >> j) & 3) == 3
                    cur_tiles_black = ((mask >> j) & 3) == 3
                    if prev_tiles_black and cur_tiles_black:
                        valid = False
                        break
                
                if valid:
                    min_prev_cost = min(min_prev_cost, dp[i - 1][prev_mask])
            
            if min_prev_cost != inf:
                dp[i][mask] = min_prev_cost + cost
    
    print(min(dp[h - 1]))

t = int(input())

while t > 0:
    t -= 1
    solve()