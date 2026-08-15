# Time Limit Exceeded”, “Wrong Answer” ou “Accepted
n = input()
lista = list(map(int, n.split()))
if lista[0] > lista[1]: print("Time Limit Exceeded")
elif lista[2] == 1: print("Accepted")
elif lista[2] == 0: print("Wrong Answer")