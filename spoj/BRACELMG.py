t = int(input())

while t:
	a, b = input().split()
	b = b + b
	if a in b:
		print('S')
	elif a[::-1] in b:
		print('S')
	else:
		print('N')
	t -= 1