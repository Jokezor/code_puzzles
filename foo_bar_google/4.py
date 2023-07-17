import random


def get_highest_power(n, k):
    ans = 0

    while n >= 1:
        n //= k
        ans += 1
    return ans


def solution(n):
    # Your code here
    # Consider more of a DP approach.
    # So first code up the DP approach with top down since we won't hit all.
    # But also look at the examples, when do we converge on the power of 2
    # series?
    n = int(n)
    ans = 0

    if n == 0:
        return ans

    while n % 2 == 0:
        print("hey")
        ans += 1
        n //= 2

    print(n, ans)
    k = get_highest_power(n, 2)
    # bit_mask = (1 << k - 1) - 1

    steps_to_higher_power = abs(n - (1 << k))
    steps_to_lower_power = abs(n - (1 << k - 1))

    if steps_to_lower_power <= steps_to_higher_power:
        ans += (k - 1) + steps_to_lower_power
    else:
        ans += k + steps_to_higher_power

    print(ans, steps_to_higher_power, steps_to_lower_power, k)

    return ans


assert solution("0") == 0
assert solution("1") == 0
assert solution("2") == 1
assert solution("4") == 2
assert solution("7") == 4
assert solution("15") == 5
assert solution("16") == 4
assert solution("31") == 6
print(solution("1000"))
assert solution("1000") == 13

# solution("".join([str(random.randint(0, 9)) for _ in range(314)]))
# solution(4)
