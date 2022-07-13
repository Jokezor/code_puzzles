from sys import stdin


def solve():
    # 
    n = int(input())
    set_one = set()
    set_two = set()
    not_possible = False
    dominoes = []

    while n:
        a, b = list(map(int, stdin.readline().rstrip().split()))
        dominoes.append((a, b))
        n -= 1

    # Try sorting the pairs.
    dominoes.sort(key=lambda dominoe: dominoe[0])
    print(dominoes)

    for a, b in dominoes:

        if a == b:
            not_possible = True

        # try set_two
        if a in set_one or b in set_one:
            if a in set_two or b in set_two:
                print(set_one, set_two, a, b)
                not_possible = True
            else:
                set_two.add(a)
                set_two.add(b)
        else:
            set_one.add(a)
            set_one.add(b)

    print("NO") if not_possible else print("YES")


def main():
    t = int(input())

    for i in range(t):
        solve()

    return 0


main()
