import math


def convert_to_common_denominator(fractions: list) -> tuple:
    denominator = 1
    for fraction in fractions:
        denominator = math.lcm(denominator, fraction[1])

    numerator = 0
    for fraction in fractions:
        numerator += int(denominator / fraction[1]) * fraction[0]

    return (numerator, denominator)


def solution(fractions):
    # Perform a BFS on the states
    # Once you reach a node with no children, you add up the probability
    # Else we continue multiply with the probability of the current cell.

    # Take the nominator and denominator separately
    # Get the lcm(x,y) this is the denominator.
    # We will generate a list of fractions for each state
    # So we run convert_to_common_denominator() for each state.
    # Then we combine them all and take the common denominator.
    fraction = convert_to_common_denominator(fractions)
    print(fraction)

    # Now lets do a BFS of all the states.
    # What do we need prior?
    return fraction


assert solution([(2, 3), (3, 5)]) == (19, 15)
assert solution([(3, 8), (5, 12)]) == (19, 24)
assert solution([(3, 14), (1, 7), (9, 14)]) == (14, 14)
assert (
    solution([(3, 14), (1, 7), (9, 14)])[0] / solution([(3, 14), (1, 7), (9, 14)])[1]
    == 1
)
