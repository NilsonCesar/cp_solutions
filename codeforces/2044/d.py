t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    numbers = set()
    for num in a:
        numbers.add(num)
    not_mode = numbers.copy()
    for j in range(n):
        if a[j] in not_mode:
            print(a[j], end=' ')
            not_mode.remove(a[j])
        else:
            print(not_mode.pop(), end=' ')

        if not len(not_mode):
            not_mode = numbers.copy()
    print()
