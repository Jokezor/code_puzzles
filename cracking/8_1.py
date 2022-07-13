def countWays(n, ways=None):
    if not ways:
        ways = [0]*(n+1)

    if n < 0:
        return 0

    if n == 0:
        return 1

    if ways[n]:
        return ways[n]

    ways[n] = countWays(n-1, ways) + countWays(n-2, ways) + countWays(n-3, ways)
    return ways[n]


print(countWays(500))