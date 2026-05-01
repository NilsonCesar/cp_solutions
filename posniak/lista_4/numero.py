import math
numeros = []

def e_primo(n):
    for i in range(2, max(3, int(math.sqrt(n)) + 1)):
        if n % i == 0 and n != i:
            return False
    return n != 1

def soma_divisores(n):
    soma = 1
    for i in range(2, n):
        if n % i == 0:
            soma += i
    return soma

a = int(input())
b = int(input())

for i in range(a + 1, b):
    soma = soma_divisores(i)
    if e_primo(soma):
        numeros.append(i)
numeros = sorted(numeros)
# print(numeros)

if len(numeros) < 2:
    print('Bazinga')
else:
    i = 0
    j = 1
    for k in range(0, len(numeros) - 1):
        if (abs(numeros[k] - numeros[k + 1]) < abs(numeros[i] - numeros[j])):
            i = k
            j = k + 1
    print(numeros[i], numeros[j])