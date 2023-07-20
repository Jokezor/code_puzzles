from fractions import Fraction


def gcd(a, b):
    """
    Calculates the greatest common divisor of a and b
    Simply takes the modulo of a with b and swap them
    """
    while b:
        a %= b
        a, b = b, a
    return a


def lcm(a, b):
    """
    Calculates lcm using the fact that x*y = lcm*gcd
    """
    return (a / gcd(a, b)) * b


def convert_to_common_denominator(fractions):
    """
    Takes in a list of fractions
    Calculates the common denominator of all the fractions
    Using that the common denominator is the least common multiple
    or lcm of all denominators.
    """
    denominator = 1
    for fraction in fractions:
        denominator = lcm(denominator, fraction.denominator)

    numerators = [
        fraction.numerator * (denominator / fraction.denominator)
        for fraction in fractions
    ]

    return (numerators, denominator)


def get_Q_R(m):
    """
    Given a matrix m, representing a markov chain of state transition
    occurences,
    returns the matrix Q holding the probability of transition
    between transient states.

    And the matrix R holding the probability of transition to absorbing states.
    """
    Q = []
    R = []
    terminal_states = []
    transient_states = []

    for i in range(len(m)):
        if all(m[i][k] == 0 for k in range(len(m[i]))):
            terminal_states.append(i)
            continue
        else:
            transient_states.append(i)

    for i in transient_states:
        q = []
        r = []

        for j in range(len(m[i])):
            if j in terminal_states:
                r.append(Fraction(m[i][j], max(1, sum(m[i]))))
            else:
                q.append(Fraction(m[i][j], max(1, sum(m[i]))))

        Q.append(q)
        R.append(r)

    return (Q, R)


def invert_I_minus_Q(Q):
    """
    Given the matrix Q.

    Will invert the matrix and return the matrix N such as

    N = (I-Q)^-1
    That is, the matrix inverse of (I-Q).
    """
    n = len(Q)
    I = [[Fraction(int(i == j)) for i in range(n)] for j in range(n)]
    I_Q = [[I[i][j] - Q[i][j] for j in range(n)] for i in range(n)]

    # Gauss elimination
    for i in range(n):
        # First swap the rows for numerical stability
        max_row = max(range(i, n), key=lambda row: abs(I_Q[row][i]))
        I_Q[i], I_Q[max_row] = I_Q[max_row], I_Q[i]
        I[i], I[max_row] = I[max_row], I[i]

        pivot = I_Q[i][i]
        I_Q[i] = [val / pivot for val in I_Q[i]]
        I[i] = [val / pivot for val in I[i]]
        for j in range(n):
            if i != j:
                ratio = I_Q[j][i]
                I_Q[j] = [I_Q[j][k] - ratio * I_Q[i][k] for k in range(n)]
                I[j] = [I[j][k] - ratio * I[i][k] for k in range(n)]

    return I


def matrix_multiply(A, B):
    """
    Given two matrices A and B, computes the matrix multiplication.
    """
    return [
        [sum(a * b for a, b in zip(row_a, col_b)) for col_b in zip(*B)] for row_a in A
    ]


def solution(m):
    """
    Calculates the probabilities of ending up in each terminal state
    of the provided markov chain, starting from state 0.

    The markov chain is described by a 2D list (m), where the value in the ith row
    and jth column represents the number of occurrences of transitioning from state i
    to state j.

    Returns a list where the first elements are numerators of the
    probabilities for each terminal state and the last element is the common denominator.
    """
    # The matrix is already in the terminal state
    if all(all(m[i][j] == 0 for j in range(len(m[i]))) for i in range(len(m))):
        return [1, 1]

    # To solve this, we can see that the matrix and the states
    # Represent an absorbing markov chain
    # Thus we can use Q as the probabilities of transient states to transient states
    # And we use R to represent the probabilities of transient states to absorbing states.
    Q, R = get_Q_R(m)

    # Get the fundamental matrix N
    N = invert_I_minus_Q(Q)

    # Get the matrix B which represents the absorbing probabilities
    B = matrix_multiply(N, R)

    # We only care about the probabilities of reaching each terminal node starting at the 0th state
    probabilities = [probability.limit_denominator() for probability in B[0]]

    # Takes the common denominator of all the fractions
    numerators, common_denominator = convert_to_common_denominator(probabilities)

    return numerators + [common_denominator]


m0 = [
    [0, 1, 0, 0, 0, 1],
    [4, 0, 0, 3, 2, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
]
assert solution(m0) == [0, 3, 2, 9, 14]
# 0/14, 3/14, 2/14, 9/14

# p0 = 4/9p1
# p1 = 0.5p0
# p2 = 0
# p3 = 3/9p1
# p4 = 2/9p1
# p5 = 0.5p0

# p0 + p1 + p2 + p3 + p4 + p5 = 1
# p2 = 0
# p0 + p1 + p3 + p4 + p5 = 1
# Remove non terminal states

# p3 + p4 + p5 = 1
# (5/9)p1 + 0.5p0 = 1
# p0 = 1

m1 = [
    [0, 2, 1, 0, 0],
    [0, 0, 0, 3, 4],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
]
assert solution(m1) == [7, 6, 8, 21]
# 7/21,  6/21, 8/21
# p0 = 1 (not terminal)
# p1 = 2/3p0, 2/3 (not terminal)
# p2 = (1/3)p0, 1/3 = 7/21
# p3 = (3/7)p1, 6/21
# p4 = (4/7)p1, 8/21
