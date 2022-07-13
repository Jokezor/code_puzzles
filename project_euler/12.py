from collections import defaultdict


memo = defaultdict(int)


def divisors(n):
    if n in memo:
        return memo[n]

    tot = 0
    for i in range(n, 0, -1):
        if i == 1:
            tot += 1
        elif n % i == 0:
            tot += 1
        memo[n] = tot
    
    return memo[n]



number = 0
max_divisors = 1

for i in range(1000000, 1, -1):
    number += i
    if number in memo:
        max_divisors = max(max_divisors, memo[number])
    max_divisors = max(max_divisors, divisors(number))

    if max_divisors >= 500:
        print(i, max_divisors)
        break


assert divisors(1) == 1
assert divisors(3) == 2
assert divisors(6) == 4
assert divisors(10) == 4
assert divisors(15) == 4
assert divisors(21) == 4
assert divisors(28) == 6

