from collections import Counter


class Solution:
    def findLonely(self, nums: list[int]) -> list[int]:
        freq_dict = Counter(nums)
        lonely_nums = []

        for num in nums:
            if freq_dict[num] == 1 and num-1 not in freq_dict and num+1 not in freq_dict:
                lonely_nums.append(num)
        return lonely_nums


assert Solution().findLonely(nums=[10,6,5,8]) == [10,8]
assert Solution().findLonely(nums=[1,3,5,3]) == [1,5]
