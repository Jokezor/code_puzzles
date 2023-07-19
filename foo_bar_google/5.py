from fractions import Fraction
from collections import defaultdict, deque


def gcd(a, b):
    while b:
        a %= b
        a, b = b, a
    return a


def lcm(a, b):
    return a / gcd(a, b) * b


def convert_to_common_denominator(fractions: list) -> tuple:
    denominator = 1
    for fraction in fractions:
        denominator = lcm(denominator, fraction.denominator)

    numerator = 0
    for fraction in fractions:
        numerator += int(denominator / fraction.denominator) * \
            fraction.numerator

    return (int(numerator), int(denominator))


"""
def convert_float_to_fraction(x, m):
    n = 0
    p = x

    while p - int(p) and n <= m:
        p = 10 * p
        n += 1

    p = int(p)
    r = math.gcd(p, 10**n)
    p //= r
    q = 10**n // r

    p = (p * r) // q
    return (p, r)
"""


def solution(m):
    # Perform a BFS on the states
    # Once you reach a node with no children, you add up the probability
    # Else we continue multiply with the probability of the current cell.

    # Take the nominator and denominator separately
    # Get the lcm(x,y) this is the denominator.
    # We will generate a list of fractions for each state
    # So we run convert_to_common_denominator() for each state.
    # Then we combine them all and take the common denominator.

    # Build up the graph
    graph = defaultdict(list)
    terminal_states = []

    for i in range(len(m)):
        if all(m[i][k] == 0 for k in range(len(m[i]))):
            terminal_states.append(i)
            break

        for j in range(len(m[i])):
            if m[i][j] > 0:
                fraction = m[i][j] / sum(m[i])
                graph[i].append((j, fraction))

    # Perform BFS until the probability is close to 0
    fractions = defaultdict(list)
    q = deque()
    q.append((0, 1))
    eps = 1e-20

    while q:
        state, prob = q.popleft()

        # A terminal state
        if not graph[state]:
            fractions[state].append(prob)

        for target_state, target_prob in graph[state]:
            new_prob = prob * target_prob
            if new_prob > eps:
                q.append((target_state, new_prob))

    probabilities = defaultdict(tuple)
    for terminal_state in fractions:
        probabilities[terminal_state] = Fraction.from_float(
            sum(fractions[terminal_state])
        ).limit_denominator()

    """
    print(probabilities)
    print(
        sum(
            [
                probabilities[state][0] / probabilities[state][1]
                for state in probabilities
            ]
        )
    )
    """

    common_numerator, common_denominator = convert_to_common_denominator(
        list(probabilities.values())
    )

    ans = {terminal_state: 0 for terminal_state in terminal_states}
    for terminal_state in sorted(probabilities.keys()):
        ans[terminal_state] = int(
            (common_denominator / probabilities[terminal_state].denominator)
            * probabilities[terminal_state].numerator
        )

    return [*ans.values(), common_denominator]

    """
    common_numerator, common_denominator = convert_to_common_denominator(
        probabilities)

    if common_numerator / common_denominator == 1:
        probabilities = [
            (common_denominator / fraction[1]) * fraction[0]
            for fraction in probabilities
        ]
        print(probabilities)
        return probabilities

    fractions = [(2, 3), (3, 5)]

    common_numerator, common_denominator = convert_to_common_denominator(
        fractions)

    if common_numerator / common_denominator == 1:
        probabilities = [
            (common_denominator / fraction[1]) * fraction[0] for fraction in fractions
        ]
        print(probabilities)
        return probabilities
    """


m0 = [
    [0, 1, 0, 0, 0, 1],
    [4, 0, 0, 3, 2, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
]
assert solution(m0) == [0, 3, 2, 9, 14]

m1 = [
    [0, 2, 1, 0, 0],
    [0, 0, 0, 3, 4],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
]
assert solution(m1) == [7, 6, 8, 21]

"""
assert solution([(2, 3), (3, 5)]) == (19, 15)
assert solution([(3, 8), (5, 12)]) == (19, 24)
assert solution([(3, 14), (1, 7), (9, 14)]) == (14, 14)
assert (
    solution([(3, 14), (1, 7), (9, 14)])[0] /
    solution([(3, 14), (1, 7), (9, 14)])[1]
    == 1
)
"""
