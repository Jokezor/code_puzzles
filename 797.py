class Solution:
    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
        def dfs(node):
            path.append(node)
            if node == len(graph) - 1:
                paths.append(path.copy())
                return

            next_nodes = graph[node]
            for next_node in next_nodes:
                dfs(next_node)
                path.pop()

        paths = []
        path = []
        if not graph or len(graph) == 0:
            return paths
        dfs(0)
        return paths


example_1 = {
    'graph': [[1,2],[3],[3],[]]
}

example_2 = {
    'graph': [[4,3,1],[3,2,4],[3],[4],[]]
}

assert Solution().allPathsSourceTarget(**example_1) == [[0,1,3],[0,2,3]]
assert Solution().allPathsSourceTarget(**example_2) == [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
