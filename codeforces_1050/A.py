t = int(input())

for i in range(t):
    x, n = map(int, input().split(" "))
    if n & 1:
        print(x)
    else:
        print(0)
