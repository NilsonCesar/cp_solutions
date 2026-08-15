input()
n = input()
n = list(map(int, n.split()))
n = sorted(n)
lista = []
soma = 0
for i, v in enumerate(n):
    soma = soma + v
    lista.append(soma)
print(sum(lista))