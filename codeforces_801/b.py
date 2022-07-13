from sys import stdin

t = int(input())

for i in range(t):
    n = list(stdin.readline().rstrip())
    
    a = list((map(int, stdin.readline().rstrip().split())))

    if len(a) % 2 != 0:
        print("Mike")
    else:
        # Need to check now.
        # Both have the same number of piles.
        min_pile = min(a)
        min_index = a.index(min_pile)

        # The leftmost pile with the least amount in it will be the one which gets empty first.
        # If the pile is even then Joe emptied it and Joe will try to take from it but fail.

        if min_index % 2 == 0:
            print("Joe")
        else:
            print("Mike")
    # n, m, k = list(map(int, stdin.readline().rstrip().split()))


