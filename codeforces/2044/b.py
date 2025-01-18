t = int(input())
for i in range(t):
    a = input()
    for c in a[::-1]:
        if c == 'p':
            print('q', end='')
        elif c == 'q':
            print('p', end='')
        else:
            print('w', end='')
    print()
