l = input()

notas = {'W': 1, 'H': 1/2, 'Q': 1/4, 'E': 1/8, 'S': 1/16, 'T': 1/32, 'X': 1/64}

while(l != '*'):
    l = l.split('/')

    ans = 0

    for compasso in l:
        if compasso == '':
            continue
        acc = 0
        for nota in compasso:
            acc += notas[nota]

        ans += acc == 1
    
    print(ans)    

    l = input()