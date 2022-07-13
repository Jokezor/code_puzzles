from sys import stdin


def solve():
    # Iterate from the start of the string
    s = stdin.readline().rstrip()
    seen = set()
    days = 1

    for c in s:
        if c not in seen and len(seen) == 3:
            days += 1
            seen = set(c)
        else:
            seen.add(c)


    print(days)




def main():
    t = int(input())

    for i in range(t):
        solve()

    return 0


main()
