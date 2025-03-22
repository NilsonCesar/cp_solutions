n = int(input())
a = list(map(int, input().split()))
nums = dict()
biggest = -1
ans = -1

for num in a:
    v = nums.setdefault(num, 0)
    nums[num] = v + 1

for num in nums:
    if nums[num] == 1:
        biggest = max(biggest, num)

if biggest > 0:
    print(a.index(biggest) + 1)
else:
    print(biggest)
