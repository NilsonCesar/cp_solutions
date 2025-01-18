r = int(input())
def inside_circle(i, j):
    return (2 * i + 1) ** 2 + (2 * j + 1) ** 2 <= 4 * r ** 2
acc = 0
J = r - 1
I = 1
ans = (r - 1) * 4 + 1

while inside_circle(I, 1):
    while not inside_circle(I, J):
        J -= 1
    acc += J
    I += 1
ans += acc * 4
print(ans)
