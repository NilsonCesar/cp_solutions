def get_sum(fen, i):
    s = 0
    i = i + 1
    while i > 0:
        s += fen[i]
        i -= i & (-i)
    return s

def update_fen(fen, n, i, v):
    i += 1
    while i <= n:
        fen[i] += v
        i += i & (-i)

def construct(arr, n):
    fen = [0] * (n + 1)
    for i in range(n):
        update_fen(fen, n, i, arr[i])
    return fen

head = 0
tail = 0
n = 3 * 10 ** 5
arr = [0] * (n)
fen = construct(arr, n)
q = int(input())
while q:
    qq = list(map(int, input().split()))
    if qq[0] == 1:
        arr[tail] = qq[1]
        update_fen(fen, n, tail, qq[1])
        tail += 1
    elif qq[0] == 2:
        update_fen(fen, n, head, -arr[head])
        head += 1
    else:
        print(get_sum(fen, qq[1] + head - 2))
    q -= 1
