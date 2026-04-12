bancas = k2 = pix = cart = []
bancas[0] = input().split()
bancas[1] = input().split()
bancas[2] = input().split()

for i in bancas:
    v1 = float(bancas[i][0])
    v2 = float(bancas[i][1])
    vpix = float(bancas[i][2])
    vcart = float(bancas[i][3])
    k2[i] = v1+v2
    pix[i] = k2[i] - (k2[i]*vpix/100)
    cart[i] = k2[i] + vcart

menor = 0
b = 0
for i in bancas:
    if i == 0:
        if pix[i]<cart[i]:
            menor = pix[i]
        else: menor = cart[i]
        b=i