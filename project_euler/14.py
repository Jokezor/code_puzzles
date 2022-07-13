from collections import defaultdict


memo = defaultdict(int)

def collatzNumber(n):
    if n in memo:
        return memo[n]
    temp = n
    if n == 1:
        return 1
    if n % 2 == 0:
        n /= 2
    else:
        n = 3*n + 1

    memo[temp] += 1
    if n in memo:
        memo[temp] += memo[n]
    else:
        memo[temp] += collatzNumber(n)
    return memo[temp]


assert collatzNumber(13) == 10
assert collatzNumber(10) == 7

max_length = 0
max_num = 0

for n in range(10**6, -1, -1):
    if collatzNumber(n) > max_length:
        max_length = collatzNumber(n)
        max_num = n

print(max_num)
