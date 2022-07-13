class Solution:
    def countElements(self, nums: list[int]) -> int:
        elements = 0

        for i in range(len(nums)):
            has_lower = False
            has_higher = False

            for j in range(len(nums)):
                if i != j:
                    if nums[j] < nums[i]:
                        has_lower = True
                    elif nums[j] > nums[i]:
                        has_higher = True
            if has_lower and has_higher:
                elements += 1

        return elements


assert Solution().countElements(nums=[11,7,2,15]) == 2
assert Solution().countElements(nums=[-3,3,3,90]) == 2
