class Solution:
    def sortJumbled(self, mapping: list[int], nums: list[int]) -> list[int]:
        def map_number(num):
            str_num = ''.join(str(mapping[int(n)]) for n in str(num))
            return int(str_num)
        return sorted(nums, key=lambda num: map_number(num))


assert Solution().sortJumbled(mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]) == [338,38,991]
assert Solution().sortJumbled(mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]) == [123,456,789]