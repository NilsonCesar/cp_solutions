n = int(input())
s = []
size = []

for i in range(n):
    l = []
    word = input()
    
    for w in word:
        l.append(w)
    
    s.append(l)
    size.append(len(l))

i = n - 1

while i >= 1:
    j = i - 1
    while j >= 0:
        if size[i] < size[j]:
            s[i] = s[i] + (['*'] * (size[j] - size[i]))
            size[i] += (size[j] - size[i])
        j -= 1
    i -= 1

max_height = max(size)
    
i = 0
stop = False

while i < max_height:
    j = n - 1
    while j >= 0:
        try:
            print(s[j][i], end = '')
        except:
            if i == max_height - 1:
                stop = True
            break
        j -= 1
    print()
    i += 1
    if stop:
        break
