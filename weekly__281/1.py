class Solution:
    def countEven(self, num: int) -> int:
        num_even = 0
        for i in range(2, num+1):
            if sum([int(digit) for digit in str(i)]) % 2 == 0:
                num_even += 1
        return num_even


assert Solution().countEven(4) == 2
assert Solution().countEven(30) == 14
