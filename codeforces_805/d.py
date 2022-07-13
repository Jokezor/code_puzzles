from collections import defaultdict
from sys import stdin


def solve():
    w = stdin.readline().rstrip()
    p = int(input())

    freq_dict = defaultdict(list)
    w_price = 0

    for ind, c in enumerate(w):
        w_price += ord(c) - ord('a') + 1
        freq_dict[ord(c) - ord('a')].append(ind)


    highest = 26
    while w_price > p and highest >= 0:
        if len(freq_dict[highest]) > 0:
            w_price -= (highest + 1)
            freq_dict[highest].pop()
        else:
            highest -= 1


    new_w = [""]*len(w)

    for char, indices in freq_dict.items():
        for index in indices:
            new_w[index] = chr(char + ord('a'))

    print("".join(new_w))
    

    


def main():
    t = int(input())

    for i in range(t):
        solve()

    return 0


main()
