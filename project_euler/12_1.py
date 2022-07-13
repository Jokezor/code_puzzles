import math 

# nth triangle number is obtained by adding the first n natural numbers.
def generate_nthtriangle_number(n):
    return sum(range(n+1))


assert generate_nthtriangle_number(1) == 1
assert generate_nthtriangle_number(2) == 3
assert generate_nthtriangle_number(3) == 6
assert generate_nthtriangle_number(4) == 10
assert generate_nthtriangle_number(5) == 15
assert generate_nthtriangle_number(6) == 21
assert generate_nthtriangle_number(7) == 28


# We can see that by checking for the lowest prime number that divides the triangle number,
# We greatly reduce the scope.
# We need only check until n...

def get_prime_factors(n):
    factors = [1]

    while n % 2 == 0:
        factors.append(2)
        n /= 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):

        while n % i == 0:
            factors.append(i)
            n /= i

    return factors



# So far the get_divisors is running in O(n) time.
# Generating triangle number in O(n) time.
# Do we know that you need to have to be at least the 500th triangle number in order to have more than 500 divisors?
# It only has 32.

# Let's check how many it has.
print(get_prime_factors(generate_nthtriangle_number(4000)))
