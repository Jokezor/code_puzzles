import heapq

n = 9
nums = [344, 12, 37, 60, 311, 613, 365, 328, 675]
goal = [0] * n

goal[0] = 344

for i in range(1, 9):
    goal[i] = max(nums[i], goal[i - 1])

print(goal)

rest = [goal[i] - nums[i] for i in range(9)]
print(rest)

heapq.heapify(rest)

ans = 0
sum = 0

while len(rest):
    n = len(rest)
    diff = heapq.heappop(rest)
    ans += (n + 1) * (diff - sum)
    sum = diff

print(ans)

# Now go through the smallest one by one
