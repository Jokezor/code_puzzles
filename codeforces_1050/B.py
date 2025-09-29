# Dont we always need to pass through all of the lasers?
t = int(input())

for i in range(t):
    n, m, x, y = map(int, input().split(" "))

    horizontals = list(map(int, input().split(" ")))
    verticals = list(map(int, input().split(" ")))

    print(n + m)
