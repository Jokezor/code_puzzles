from fractions import Fraction
from collections import defaultdict, deque


def gcd(a, b):
    while b:
        a %= b
        a, b = b, a
    return a


def lcm(a, b):
    return (a / gcd(a, b)) * b


def find_best_fraction(numerator, denominator, max_denominator=1000000):
    if max_denominator < 1:
        raise ValueError("max_denominator should be at least 1")
    if denominator <= max_denominator:
        return Fraction(numerator, denominator)

    p0, q0, p1, q1 = 0, 1, 1, 0
    n, d = numerator, denominator
    while True:
        a = n // d
        q2 = q0 + a * q1
        if q2 > max_denominator:
            break
        p0, q0, p1, q1 = p1, q1, p0 + a * p1, q2
        n, d = d, n - a * d

    k = (max_denominator - q0) // q1
    bound1 = Fraction(p0 + k * p1, q0 + k * q1)
    bound2 = Fraction(p1, q1)
    if abs(bound2 - Fraction(numerator, denominator)) <= abs(
        bound1 - Fraction(numerator, denominator)
    ):
        return bound2
    else:
        return bound1


def convert_to_common_denominator(fractions):
    denominator = 1
    for fraction in fractions:
        denominator = lcm(denominator, fraction.denominator)

    numerator = 0
    for fraction in fractions:
        numerator += int(denominator / fraction.denominator) * fraction.numerator

    return (int(numerator), int(denominator))


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
            continue

        for j in range(len(m[i])):
            if m[i][j] > 0:
                fraction = (m[i][j], sum(m[i]))
                graph[i].append((j, fraction))

    # Perform BFS until the probability is close to 0
    fractions = {}
    q = deque()
    q.append((0, (1, 1), [0]))
    paths = []
    eps = 0.00000001

    while q:
        state, prob, current_path = q.popleft()

        # A terminal state
        if not graph[state]:
            paths.append(current_path[:])

            # Remove the last since its a terminal
            current_path.pop()
            new_fraction = Fraction(prob[0], prob[1])
            if state not in fractions:
                fractions[state] = new_fraction
            else:
                fractions[state] = new_fraction + fractions[state]

        for target_state, target_prob in graph[state]:
            new_prob = (
                prob[0] * target_prob[0],
                prob[1] * target_prob[1],
            )
            if (float(new_prob[0]) / new_prob[1]) > eps:
                q.append((target_state, new_prob, current_path + [target_state]))

    print(paths)
    probabilities = {}
    for terminal_state in fractions:
        probabilities[terminal_state] = fractions[terminal_state].limit_denominator(
            1000
        )

    _, common_denominator = convert_to_common_denominator(list(probabilities.values()))

    ans = {terminal_state: 0 for terminal_state in terminal_states}
    for terminal_state in sorted(probabilities.keys()):
        ans[terminal_state] = int(
            (common_denominator / probabilities[terminal_state].denominator)
            * probabilities[terminal_state].numerator
        )

    # print([*ans.values(), common_denominator])
    result = list(ans.values())
    result.append(common_denominator)
    # print(result)

    return result


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
