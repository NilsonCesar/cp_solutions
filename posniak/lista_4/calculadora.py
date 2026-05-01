s = input()
numeros = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
ops = ['+', '-', '/', '*']
chain = []

for d in s:
    if d in numeros:
        chain.append(d)
    elif d in ops:
        chain.append(d)


i = 0
processed_chain = []

while i < len(chain):
    num = ''
    while i < len(chain) and chain[i] in numeros:
        num += chain[i]
        i += 1
    if num == '':
        processed_chain.append(chain[i])
        i += 1
    else:
        processed_chain.append(int(num))

chain = processed_chain
# print(chain)

result = chain[0]
chain = chain[1:]
a = 0
numero = False
op = ''

for c in chain:
    if not numero:
        op = c
    else:
        a = c
        if op == '+':
            result += a
        if op == '-':
            result -= a
        if op == '*':
            result *= a
        if op == '/':
            if (a == 0):
                print("caiu os butcha dos bolsos")
                exit(0)
            result /= a
    numero = not numero

print(f'{result:.2f}')