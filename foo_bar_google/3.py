def number_in_base(n, b, k):
    """
    Takes a number n and given base b, outputs a string representation of n
    in base b.
    Makes sure to maintain the length of the number with prepending 0s.
    """
    if n == 0:
        return "0"
    digits = ""
    while n:
        digits += str(int(n % b))
        n //= b
    return digits[::-1].zfill(k)


def solution(n, b):
    # Make the subtraction until a cycle is found.
    z = int(n, b)
    k = len(n)

    ans = 0
    i = 1
    old_z = z

    # Maintain a map of where in the order the number was first seen
    seen_digits = {z: i}

    while True:
        i += 1
        digits = number_in_base(z, b, k)
        x = sorted(digits, reverse=True)
        y = sorted(digits)
        z = int("".join(x), b) - int("".join(y), b)

        if z in seen_digits:
            ans = seen_digits[old_z] - seen_digits[z] + 1
            break

        old_z = z
        seen_digits[z] = i

    return ans


assert solution("0", 10) == 1
assert solution("1211", 10) == 1
assert solution("210022", 3) == 3
