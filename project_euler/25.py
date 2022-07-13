from functools import cache

@cache
def fibonacci(n):
    if n <= 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)


assert fibonacci(1) == 1
assert fibonacci(2) == 1
assert fibonacci(3) == 2
assert fibonacci(4) == 3
assert fibonacci(5) == 5
assert fibonacci(6) == 8
assert fibonacci(7) == 13
assert fibonacci(8) == 21
assert fibonacci(9) == 34
assert fibonacci(10) == 55
assert fibonacci(11) == 89
assert fibonacci(12) == 144


for i in range(10000):
    fib_i = fibonacci(i)
    if len(str(fib_i)) >= 1000:
        print(i)
        break


