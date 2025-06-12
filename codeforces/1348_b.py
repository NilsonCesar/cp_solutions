t = int(input())

for k in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    nums = set()
    for num in a:
        nums.add(num)

    K = list(nums)
    if len(nums) > k:
        print(-1)
        continue
        
    if len(nums) < k:
        for i in range(1, k + 1):
            if not i in K:
                K.append(i)
                if len(K) == k:
                    break
        K.sort()

    print(n * k)
    for i in range(n):
        for num in K:
            print(num, end=' ')
    print()