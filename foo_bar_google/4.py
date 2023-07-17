import random


def get_highest_power(n, k):
    ans = 0

    while n >= 1:
        n //= k
        ans += 1
    return ans


def solution(n):
    # Your code here
    n = int(n)
    ans = 0

    while n > 1:
        if n % 2 == 0:
            n //= 2
        elif n % 4 == 1 or n == 3:
            n -= 1
        else:
            n += 1
        ans += 1

    return ans


assert solution("0") == 0
assert solution("1") == 0
assert solution("2") == 1
assert solution("3") == 2
assert solution("4") == 2
assert solution("5") == 3
assert solution("6") == 3
assert solution("7") == 4
assert solution("8") == 3
assert solution("9") == 4
assert solution("10") == 4
assert solution("11") == 5
assert solution("12") == 4
assert solution("13") == 5
assert solution("14") == 5
assert solution("15") == 5
assert solution("16") == 4
assert solution("17") == 5
assert solution("18") == 5
assert solution("31") == 6
assert solution("29") == 7
assert solution(f"{29*16}") == 11
assert solution(f"{17*32}") == 10
assert solution("1000") == 12

# solution("".join([str(random.randint(0, 9)) for _ in range(314)]))
# solution(4)
