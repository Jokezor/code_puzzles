from sys import stdin


def solve():
    # Divide by 10**9, 10**8 until above 1.
    # Then subtract 10**k from m
    m = int(stdin.readline().rstrip())

    k = 9

    while m / 10 ** k < 1:
        k -= 1

    print(m - 10**k)


def main():
    t = int(input())

    for i in range(t):
        solve()

    return 0


main()
