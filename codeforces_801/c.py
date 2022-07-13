from sys import stdin


def solve():
    n, m = list(map(int, stdin.readline().rstrip().split()))

    if (m + n - 1) % 2 != 0:
        print("NO")
        return

    matrix = []
    for _ in range(n):
        row = list(map(int, stdin.readline().rstrip().split()))
        matrix.append(row)

    maximum = [[-float('inf')] * m] * n
    minimum = [[float('inf')] * m] * n

    for row in range(n):
        for col in range(m):
            if row == 0 and col == 0:
                minimum[row][col] = maximum[row][col] = 0
            elif row == 0:
                minimum[row][col] = minimum[row][col-1]
                maximum[row][col] = maximum[row][col-1]
            elif col == 0:
                minimum[row][col] = minimum[row-1][col]
                maximum[row][col] = maximum[row-1][col]
            else:
                maximum[row][col] = max(maximum[row - 1][col], maximum[row][col - 1])
                minimum[row][col] = min(minimum[row - 1][col], minimum[row][col - 1])
            minimum[row][col] += matrix[row][col]
            maximum[row][col] += matrix[row][col]

    if minimum[n-1][m-1] > 0 or maximum[n-1][m-1] < 0:
        print("NO")
    else:
        print("YES")

    # Append a row and col of zeroes and
    # Keep adding the one to the right or left.


t = int(input())
M = N = 1010

for i in range(t):
    solve()


