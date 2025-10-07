import math


t = int(input())

for _ in range(t):
    a, b = map(int, input().split(" "))
    k = (a+b)/(2*a) + math.sqrt((a*a + 2*a*b + b*b - 4*a*b)/(4*a*a))
    k = (a+b)/(2*a)
    print(k)
    print(a*k + b/k)

