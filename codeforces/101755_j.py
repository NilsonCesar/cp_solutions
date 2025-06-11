n = int(input())
a = list(map(int, input().split()))
pairs = {}
ans = 0
 
for num in a:
	pairs[num] = pairs.get(num, 0) + 1
 
keys = list(pairs.keys())
 
for i in range(len(keys)):
	if pairs[keys[i]] < 2:
		continue
	for j in range(i + 1, len(keys)):
		if pairs[keys[j]] < 2:
			continue
		np = min(pairs[keys[i]], pairs[keys[j]])
		pairs[keys[i]] -= 2 * (np // 2)
		pairs[keys[j]] -= 2 * (np // 2)
		ans += np // 2
		if pairs[keys[i]] < 2:
			break
 
for k in keys:
	ans += pairs[k] // 4

print(ans)