from collections import Counter


class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq_dict = Counter(s)
        sorted_string = sorted(s, reverse=True)
        new_string = sorted_string

        # I need some way to subtract from the already sorted string in order to match the requirements.
        current_char = sorted_string[0]
        concurrent = 0

        for ind, char in enumerate(new_string):
            print(current_char, concurrent)
            if char == current_char:
                concurrent += 1
            else:
                current_char = char
                concurrent = 1

            if concurrent > repeatLimit:
                # No, I actually would have to move it to a position that would fit. ://
                new_string[ind] = ""

        print(new_string)
        return new_string


assert Solution().repeatLimitedString("xzz", 1) == "zxz"
assert Solution().repeatLimitedString("cczazcc", 3) == "zzcccac"