import functools


def count_numbers_with_same_bit(num, current_power, next_power):
    """
    Counts the numbers less than num with a bit set in current_power.

    current_power is the bit position we want to check given as 2^i
    next_power is the next bit position we want to check given as a number 2^(i+1)
    """
    res = (num // next_power) * current_power
    res += min(max(num % next_power - current_power + 1, 0), current_power)
    return res


def solution(start, length):
    """
    Calculates the xor by considering the numbers row by row.

    Does this by considering that only numbers with the same bit set will
    affect each order when performing xor.

    Store each rows xor by calculating the numbers with same bit set.
    If the count is odd, then it will be set for this row.
    This is added to the index of rows.

    Finally, the sequence is reduced by performing xor on each entry.
    """
    rows = [0] * length
    powers_of_two = [1 << i for i in range(32)]

    for row in range(length):
        i = 0
        smallest_in_row = start + row * length
        biggest_in_row = smallest_in_row + length - row - 1

        while powers_of_two[i] <= biggest_in_row:
            num_b = count_numbers_with_same_bit(
                biggest_in_row, powers_of_two[i], powers_of_two[i + 1]
            )
            num_a = count_numbers_with_same_bit(
                max(smallest_in_row - 1,
                    0), powers_of_two[i], powers_of_two[i + 1]
            )

            # Calculate the numbers with bits that we have counted for b
            # which should not be included
            if smallest_in_row == biggest_in_row and (num_b - num_a):
                rows[row] += powers_of_two[i]
            elif (num_b - num_a) % 2:
                rows[row] += powers_of_two[i]

            i += 1

    # Final result is to xor all the rows.
    res = functools.reduce(lambda a, b: a ^ b, rows)

    return res


assert count_numbers_with_same_bit(1, 1, 2) == 1
assert count_numbers_with_same_bit(2, 1, 2) == 1
assert count_numbers_with_same_bit(3, 1, 2) == 2
assert count_numbers_with_same_bit(4, 1, 2) == 2
assert count_numbers_with_same_bit(3, 2, 4) == 2
assert solution(0, 3) == 2
assert solution(17, 4) == 14
