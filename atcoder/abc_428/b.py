N, K = map(int, input().split())
S = input()
count = 0
ss = set()
for i in range(0, N - K + 1):
    tmp_count = 0
    for j in range(0, N - K + 1):
        if S[i: i + K] == S[j: j + K]:
            tmp_count += 1
    
    if tmp_count > count:
        count = tmp_count
        ss = set()
        ss.add(S[i: i + K])
    elif tmp_count == count:
        ss.add(S[i: i + K])
    
print(count)
for s in sorted(ss):
    print(s, end=' ')
print()