import string


class Solution:
    def cellsInRange(self, s: str) -> list[str]:
        cells_in_range = []
        cells = s.split(':')
        alphabet = list(string.ascii_uppercase)

        for i in range(alphabet.index(cells[0][0]), alphabet.index(cells[-1][0])+1):
            for j in range(int(cells[0][1]), int(cells[-1][1]) + 1):
                cells_in_range.append(f'{alphabet[i]}{j}')
        return cells_in_range


assert Solution().cellsInRange("K1:L2") == ["K1","K2","L1","L2"]
assert Solution().cellsInRange("A1:F1") == ["A1","B1","C1","D1","E1","F1"]
