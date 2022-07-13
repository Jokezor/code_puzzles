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


