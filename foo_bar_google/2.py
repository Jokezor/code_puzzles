def solution(x, y):
    # take the sum of the numbers
    n = x + y

    # the id is given by the order.

    # we only need to consider the position in its own rank given its sum.

    # get the id from summing up all the previous ids, we only want the count of each sum row
    # which we get from taking sum_i=1^(n-2) {i} since there are n-1 combinations
    # for each sum.
    combinations_prior = (n - 2) * (n - 1) // 2

    # then we add x since that is the xth order id in that rank given its sum.
    return str(combinations_prior + x)


assert solution(1, 1) == "1"
assert solution(1, 2) == "2"
assert solution(2, 1) == "3"
assert solution(1, 3) == "4"
assert solution(2, 2) == "5"
assert solution(3, 1) == "6"
assert solution(1, 4) == "7"
assert solution(2, 3) == "8"
assert solution(3, 2) == "9"
assert solution(4, 1) == "10"
assert solution(5, 10) == "96"
