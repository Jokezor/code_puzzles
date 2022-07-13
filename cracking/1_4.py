from collections import Counter


def palindrome_permutation(str1):
    bit_vector = 0

    for c in str1.lower():
        if c == ' ':
            continue
        x = ord(c)

        mask = 1 << x

        if (bit_vector & mask) == 0:
            bit_vector |= mask
        else:
            bit_vector &= ~mask

    return bit_vector == 0 or ((bit_vector & (bit_vector - 1)) == 0)


print(palindrome_permutation("Tact Coa"))
