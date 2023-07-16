def solution(s):
    i = 1
    k = 1
    j = 0

    # Go through the string to find the longest recurring subsequence.
    # Checks for each character if its part of a current subsequence.

    while k < len(s):
        if s[k] == s[j]:
            j += 1
            j %= i
            k += 1
        # Edge case handles when we would increment k without checking
        # if it may be part of a subsequence if we would restart it.
        elif s[k] == s[0]:
            i = k
            j = 0
        else:
            i = k + 1
            j = 0
            k += 1
    return len(s) // i


assert solution("a") == 1
assert solution("abccbaabccba") == 2
assert solution("abcabcabcabc") == 4
assert solution("abcaaaabcaaa") == 2
