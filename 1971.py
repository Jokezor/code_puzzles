from collections import defaultdict


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


class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:

        graph_to_traverse = BiDirectionalGraph()
        # Well first we need to build the graph
        for edge in edges:
            graph_to_traverse.addEdge(edge[0], edge[1])
            graph_to_traverse.addEdge(edge[1], edge[0])

        return graph_to_traverse.DFS(source, destination)


example_1 = {
    'n': 3,
    'edges': [[0, 1], [1, 2], [2, 0]],
    'source': 0,
    'destination': 2
}

example_2 = {
    'n': 6,
    'edges': [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]],
    'source': 0,
    'destination': 5
}

example_3 = {
    'n': 10,
    'edges': [[0,7],[0,8],[6,1],[2,0],[0,4],[5,8],[4,7],[1,3],[3,5],[6,5]],
    'source': 7,
    'destination': 5
}

assert Solution().validPath(**example_1) == True
assert Solution().validPath(**example_2) == False
assert Solution().validPath(**example_3) == True
