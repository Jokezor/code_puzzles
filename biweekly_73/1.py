from collections import Counter

class Solution:
    def mostFrequent(self, nums: list[int], key: int) -> int:
        freq_dict = Counter()
        for i in range(1, len(nums)):
            if nums[i-1] == key:
                freq_dict[nums[i]] += 1

        max_times, max_ind = 0, 0
        for num in freq_dict:
            if freq_dict[num] > max_times:
                max_times = freq_dict[num]
                max_ind = num

        return max_ind


assert Solution().mostFrequent([1,100,200,1,100], 1) == 100
assert Solution().mostFrequent([2,2,2,2,3], 2) == 2
