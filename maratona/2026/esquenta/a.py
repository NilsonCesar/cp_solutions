n = int(input())
lista = []
for i in range(n):
  l = input()
  lista.append(list(map(int, l.split())))
maior = 0
venc = 0
empate = []
for i in range(n):
  if i==0: 
    maior = lista[i][0]
    venc = lista[i]
    empate.append(lista[i])
  elif maior < lista[i][0]: 
    maior = lista[i][0]
    venc = lista[i]
    empate = [lista[i]]
  elif maior == lista[i][0]: empate.append(lista[i])
empate2 = []
if len(empate)>1:
  menor = 0
  for i, e in enumerate(empate):
    if i == 0: 
      menor = e[1]
      venc = e
    elif menor > e[1]: 
      menor = e[1]
      venc = e
    elif menor == e[1]: empate2.append(e)
  print(lista.index(venc)+1)
elif len(empate2)>0:
  menori =0 
  for i, e2 in enumerate(empate2):
    if i ==0:
      menori = lista.index(e2)
      venc = e2
    elif menori > lista.index(e2): 
      menori = lista.index(e2)
      venc = e2
  print(lista.index(venc)+1)
else: 
  print(lista.index(venc)+1)
   