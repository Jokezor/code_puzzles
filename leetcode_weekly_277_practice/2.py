from itertools import chain

class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        positive_numbers = [num for num in nums if num > 0]
        negative_numbers = [num for num in nums if num < 0]

        return list(chain(*zip(positive_numbers, negative_numbers)))


assert Solution().rearrangeArray(nums=[3,1,-2,-5,2,-4]) == [3,-2,1,-5,2,-4]
assert Solution().rearrangeArray(nums=[-1,1]) == [1,-1]
