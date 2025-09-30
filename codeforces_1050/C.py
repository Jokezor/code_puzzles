# FJ takes 1 minute to get to the other side.
# If he runs to the other side he gains one point.
# Start at 0.

# Audio plays n times.
# At start of a_ith minute, FJ must be at b_ith side.
# FJ will run until the start of the m_th minute.

# 2, 4
# 0 -> 1, wait until 2, then run to 0.
# FJ does not run at 4th since that is >= m.

# So he can basically run until m.

# 2 4
# 2 1
# 4 0

# at 0 to 1 +1
# at 1 to 1 (0)
# at 2 to 0 +1
# at 3 to 0 (0)

# 2 7
# 1 1
# 4 0

# at 0 to 1.
# at 1 to 0
# at 2 to 1
# at 3 to 0
# at 4 to 1
# at 5 to 0
# at 6 to 1
# He stops before 7.

# 4 9
# 1 0
# 2 0
# 6 1
# 9 0

# at 0 to 0 (0)
# at 1 to 0 (0)
# at 2 to 1 +1
# at 3 to 0 +1
# at 4 to 1 +1
# at 5 to 1 (0)
# at 6 to 0 +1
# at 7 to 1 +1
# at 8 to 0 +1

# So basically, check for each i if b[i+1]

t = int(input())

for _ in range(t):
    n, m = list(map(int, input().split(" ")))
    rules = {}

    for _ in range(n):
        a, b = list(map(int, input().split(" ")))
        rules[a] = b

    points = 0
    curr = 0

    for i in range(m):
        next_rule = rules.get(i+1, -1)

        next_curr = (curr + 1) % 2;
        if next_curr != next_rule and next_rule != -1:
            continue
        else:
            curr = next_curr
            points += 1



    print(points)


