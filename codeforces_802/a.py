from sys import stdin

t = int(input())

for i in range(t):
    n, m = list(map(int, stdin.readline().rstrip().split()))

    matrix = []
    h = w = 0

    for i in range(n):
        row = list(map(int, stdin.readline().rstrip().split()))
        matrix.append(row)

    # Get max_value
    max_value = -float('inf')
    max_coordinates = (0, 0)

    for ind, row in enumerate(matrix):
        max_candidate = max(row)
        if max_candidate > max_value:
            max_value = max_candidate
            max_coordinates = (ind, row.index(max_candidate))

    row, col = max_coordinates
    h = max(n - row, row + 1) 
    w = max(m - col, col + 1)

    print(h * w)

