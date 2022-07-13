class Solution:
    def getAncestors(self, n: int, edges: list[list[int]]) -> list[list[int]]:
        visited_nodes = {}

        for i in range(n):
            visited_nodes[i] = []

        # First get the total reachable nodes
        for edge in edges:
            if edge[0] not in visited_nodes[edge[1]]:
                visited_nodes[edge[1]].append(edge[0])

        def dfs(node, graph, key):
            if node not in graph[key] and node != key:
                graph[key].append(node)
            for neighbour in graph[node]:
                dfs(neighbour, graph, key)

        for i in range(n):
            dfs(i, visited_nodes, i)

        return [sorted(visited_nodes[node]) for node in visited_nodes]



assert Solution().getAncestors(n = 8, edges = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]) == [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
assert Solution().getAncestors(n = 5, edges = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]) == [[],[0],[0,1],[0,1,2],[0,1,2,3]]
