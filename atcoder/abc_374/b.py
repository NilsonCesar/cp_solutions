s = input()
t = input()

for i in range(min(len(s), len(t))):
    if s[i] != t[i]:
        print(i + 1)
        exit()

if len(s) == len(t):
    print(0)
elif len(s) < len(t):
    print(len(s) + 1)
else:
    print(len(t) + 1)