class Solution:
    def numberOfArrays(self, differences: list[int], lower: int, upper: int) -> int:
        running_difference = 0
        biggest = smallest = 0

        for difference in differences:
            running_difference += difference
            biggest = max(biggest, running_difference)
            smallest = min(smallest, running_difference)

        array_interval = biggest - smallest
        allowed_interval = upper - lower

        if array_interval > allowed_interval:
            return 0

        return allowed_interval - array_interval + 1


differences1 = [1,-3,4]
lower1 = 1
upper1 = 6

differences2 = [3,-4,5,1,-2]
lower2 = -4
upper2 = 5

differences3 = [4,-7,2]
lower3 = 3
upper3 = 6


assert Solution().numberOfArrays(differences=differences1, lower=lower1, upper=upper1) == 2
assert Solution().numberOfArrays(differences=differences2, lower=lower2, upper=upper2) == 4
assert Solution().numberOfArrays(differences=differences3, lower=lower3, upper=upper3) == 0
