bancas = []
pix = []
cart = []

for i in range(3):
    lista_str = input().split()
    bancas.append([float(x) for x in lista_str])

for v in bancas:
    kg2 = v[0] + v[1]
    vpix = v[2]
    vcart = v[3]

    pix.append(kg2 - (kg2*vpix/100))
    cart.append(kg2+vcart)

menor =0
b = 0
for i in range(3):
    if i==0:
        menor = pix[i] if pix[i]<cart[i] else cart[i]
        b = 1
    elif pix[i]<menor or cart[i]<menor:
        menor = pix[i] if pix[i]<cart[i] else cart[i]
        b=i+1

print(f'R$ {menor:.2f} Banca {b}')