from functools import cache

@cache
def factorial(a):
    if a == 0:
        return 0
    if a == 1:
        return 1

    return factorial(a-1) * factorial(a-2)

factorial(5)
