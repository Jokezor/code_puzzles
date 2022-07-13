class DJS:
    def __init__(self, alphabet):
        self.parent = {char: char for char in alphabet}
        self.values = {char: 1.0 for char in alphabet}

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x], val = self.find(self.parent[x])
            self.values[x] *= val
        return self.parent[x], self.values[x]

    def union(self, y, x, val):
        x, x_value = self.find(x)
        y, y_value = self.find(y)
        if x == y:
            return
        self.parent[y] = self.parent[x]
        self.values[y] = val * x_value / y_value


class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]:
        alphabet = set(sum(equations, []))
        disjoint_set = DJS(alphabet)

        for (y, x), val in zip(equations, values):
            disjoint_set.union(y, x, val)

        result = []
        for y, x in queries:
            if x not in alphabet or y not in alphabet:
                result.append(-1.0)
                continue
            y, y_value = disjoint_set.find(y)
            x, x_value = disjoint_set.find(x)
            if x == y:
                result.append(y_value / x_value)
            else:
                result.append(-1.0)
        return result


equations = [["a", "b"], ["b", "c"]]
values = [2.0, 3.0]
queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
assert Solution().calcEquation(equations, values, queries) == [6.00000, 0.50000, -1.00000, 1.00000, -1.00000]
