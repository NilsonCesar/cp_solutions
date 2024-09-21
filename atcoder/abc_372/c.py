n, q = map(int, input().split())
s = list(input())
ans = 0

for i in range(n - 2):
    if s[i] == "A" and s[i + 1] == "B" and s[i + 2] == "C":
        ans += 1

for _ in range(q):
    x, c = input().split()
    x = int(x) - 1

    for i in range(3):
        idx = x - i
        if idx >= 0 and idx < n - 2:
            if s[idx] == "A" and s[idx + 1] == "B" and s[idx + 2] == "C":
                ans -= 1
    
    s[x] = c

    for i in range(3):
        idx = x - i
        if idx >= 0 and idx < n - 2:
            if s[idx] == "A" and s[idx + 1] == "B" and s[idx + 2] == "C":
                ans += 1

    print(ans)