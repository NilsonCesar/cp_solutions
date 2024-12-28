k = int(input())
s = input()
t = input()
dist = abs(len(s) - len(t))

if dist > k:
    print("No")
elif dist == 1:
    diff = 0
    if len(s) > len(t):
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i, j = i + 1, j + 1
            else:
                diff += 1
                i += 1
    else:
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i, j = i + 1, j + 1
            else:
                diff += 1
                j += 1
    if diff > k:
        print("No")
    else:
        print("Yes")
else:
    diff = 0
    for i in range(len(s)):
        if s[i] != t[i]:
            diff += 1
    if diff > k:
        print("No")
    else:
        print("Yes")
