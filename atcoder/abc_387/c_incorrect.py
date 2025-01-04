def check_snake_number(n):
    n_str = str(n)
    p = int(n_str[0])
    for i in range(1, len(n_str)):
        if p <= int(n_str[i]):
            return False
    return True

def found_snake_numbers(n):
    n_str = str(n)
    if not check_snake_number(n):
        return 0
    first_n = int(n_str[0])
    pos = 1
    for i in range(1, len(n_str)):
        pos *= (first_n - int(n_str[i]))
    return pos

def found_snake_numbers_p10(n, l):
    return n ** (l - 1)

def next_inc(n):
    return str(n)[0] == '1'

def found_last_snake_number(n):
    n_str = str(n)
    p = int(n_str[0])
    last = str(p)
    for i in range(1, len(n_str)):
        if p <= int(n_str[i]):
            last = last + str(p - 1)
        else:
            last = last + n_str[i]
    return int(last)

l, r = map(int, input().split())
ans = found_snake_numbers(l)
inc = 10 ** (len(str(l)) - 1)
lim = len(str(inc))
next_n = (int(str(l)[0]) + 1) * inc

if next_inc(next_n):
    inc *= 10
    lim += 1

while next_n <= r:
    print(ans, next_n, inc)
    ans += found_snake_numbers_p10(int(str(next_n)[0]), lim)
    next_n += inc
    if next_inc(next_n):
        inc *= 10
        lim += 1

if not check_snake_number(r):
    r = found_last_snake_number(r)
    print(r)
ans -= found_snake_numbers(r) - 1
print(ans)
