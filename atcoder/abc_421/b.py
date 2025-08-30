def rev(a: int):
    return int(str(a)[::-1])

def f(a: int):
    return rev(a)

x, y = map(int, input().split())
seq = [0] * 10
seq[0] = x
seq[1] = y

for i in range(2, 10):
    seq[i] = f(seq[i - 1] + seq[i - 2])

print(seq[9])