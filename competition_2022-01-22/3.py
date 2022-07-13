class Solution:
    def highestRankedKItems(self, grid: list[list[int]], pricing: list[int], start: list[int], k: int) -> list[list[int]]:
        pass


example_1 = {
    'grid': [[1,2,0,1],[1,3,0,1],[0,2,5,1]],
    'pricing': [2,5],
    'start': [0,0],
    'k': 3
}

example_2 = {
    'grid': [[1,2,0,1],[1,3,3,1],[0,2,5,1]],
    'pricing': [2,3],
    'start': [2,3],
    'k': 2
}

example_3 = {
    'grid': [[1,1,1],[0,0,1],[2,3,4]],
    'pricing': [2,3],
    'start': [0,0],
    'k': 3
}

assert Solution().highestRankedKItems(**example_1) == [[0,1],[1,1],[2,1]]
assert Solution().highestRankedKItems(**example_2) == [[2,1],[1,2]]
assert Solution().highestRankedKItems(**example_3) == [[2,1],[2,0]]
