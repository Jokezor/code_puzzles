from collections import defaultdict


# UnionFind class
class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(size)]

    def find(self, x):
        while x != self.root[x]:
            x = self.root[x]
        return x

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            self.root[rootY] = rootX

    def connected(self, x, y):
        return self.find(x) == self.find(y)


class BiDirectionalGraph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited, destination):
        visited.add(v)

        if v == destination:
            return

        for neighbour in self.graph[v]:
            if neighbour not in visited:
                self.DFSUtil(neighbour, visited, destination)

    def DFS(self, v, destination):
        visited = set()
        self.DFSUtil(v, visited, destination)

        if destination in visited:
            return True
        else:
            return False


class BiDirectionalGraphExample:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:

        graph_to_traverse = BiDirectionalGraph()
        # Well first we need to build the graph
        for edge in edges:
            graph_to_traverse.addEdge(edge[0], edge[1])
            graph_to_traverse.addEdge(edge[1], edge[0])

        return graph_to_traverse.DFS(source, destination)


class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        a = nums[:]

        def partition(start, end, array):

            while start < end:

                while start < len(array) and array[start] <= pivot:
                    start += 1

                while array[end] > pivot:
                    end -= 1

                if (start < end):
                    array[start], array[end] = array[end], array[start]

            return end

        print(a)
        partition(0, len(a)-1, a)

        print(a)

        return a


assert Solution().pivotArray([9,12,5,10,14,3,10], 10) == [9,5,3,10,10,12,14]
assert Solution().pivotArray([-3,4,3,2], 2) == [-3,2,4,3]
assert Solution().pivotArray([4,0,4,5,-11], 5) == [4,0,4,-11,5]
assert Solution().pivotArray([-8,0,7,-7,19,15,6,-5,-10,11,-6,-5,20,3,-6,10,-2], -5) == [-8,-7,-10,-6,-6,-5,-5,0,7,19,15,6,11,20,3,10,-2]