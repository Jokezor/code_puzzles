#  just make a factorial calculation with dynamic programming and convert the value to a string and sum it.
memory = {}

def fact(n):
    if n in memory:
        return memory[n]

    if n == 1:
        return n

    memory[n] = n*fact(n-1)
    return n*fact(n-1)

num = fact(100)
tot = 0

for c in str(num):
    tot += int(c)

print(tot)
