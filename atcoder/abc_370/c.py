s = input()
t = input()
ans = []

diffs = []

for i in range(len(s)):
    if s[i] != t[i]:
        diffs.append(i)

while s != t:
    j = 1
    tmp_i = 0
    tmp_s = s[:diffs[0]] + t[diffs[0]] + s[diffs[0] + 1:]
    for i in diffs[1:]:
        if (s[:i] + t[i] + s[i + 1:]) < tmp_s:
            tmp_i = j
            tmp_s = s[:i] + t[i] + s[i + 1:]
        j += 1
        
    ans.append(tmp_s)
    s = tmp_s
    diffs = diffs[:tmp_i] + diffs[tmp_i + 1:]
    

print(len(ans))
for a in ans:
    print(a)