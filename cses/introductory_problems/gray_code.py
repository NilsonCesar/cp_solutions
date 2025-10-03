def gray_code(n):
    if n == 1:
        return [['0'], ['1']]
    prev_code = gray_code(n - 1)
    code = []
    for p in prev_code:
        code.append(['0'] + p)
    for p in prev_code[::-1]:
        code.append(['1'] + p)
    return code

n = int(input())
code = gray_code(n)
for c in code:
    ans = ''
    for x in c:
        ans += x
    print(ans)