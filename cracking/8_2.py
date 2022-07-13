def calc_path(maze, row, col, path, failed_points):
    if col < 0 or row < 0 or not maze[row][col]:
        return False

    if (row, col) in failed_points:
        return False

    is_at_origin = row == 0 and col == 0

    if is_at_origin or calc_path(maze, row, col-1, path, failed_points) or calc_path(maze, row-1, col, path, failed_points):
        path.append((row, col))
        return True

    failed_points.add((row, col))
    return False


def get_path(maze):

    if not maze:
        return None

    path = []
    failed_points = set()
    row, col = len(maze) - 1, len(maze[0]) - 1

    calc_path(maze, row, col, path, failed_points)
    print(path)
    return path


maze_1 = [[1, 1],
          [1, 1]]
maze_2 = [
    [1, 0, 0, 0],
    [1, 1, 1, 0],
    [0, 0, 1, 0],
    [0, 0, 1, 1]
]

assert get_path(maze_1) == [(0,0), (1,0), (1,1)]
assert get_path(maze_2) == [
    (0,0), (1,0), (1,1), (1,2), (2,2), (3,2), (3,3)
]
