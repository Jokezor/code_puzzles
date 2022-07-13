class Solution:
    def minimalKSum(self, nums: list[int], k: int) -> int:
        sorted_nums = sorted(nums)
        i = 1

        if len(nums) == 1:
            if nums[0] == 1:
                k_sum = 2
            else:
                k_sum = 1
            k -= 1
        else:
            k_sum = sum(range(sorted_nums[0]))
            k -= sorted_nums[0]-1

        while i < len(nums) and k:
            num = sorted_nums[i-1] + 1
            while num < sorted_nums[i] and k:
                k_sum += num
                k -= 1
                num += 1
            i += 1

        if k:
            k_sum += sum(range(sorted_nums[-1]+1, sorted_nums[-1]+k+1))

        return k_sum


assert Solution().minimalKSum(nums = [1,4,25,10,25], k = 2) == 5
assert Solution().minimalKSum(nums = [5,6], k = 6) == 25
