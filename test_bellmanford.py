class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.edges = []

    def add_edge(self, source, destination, weight):
        self.edges.append((source, destination, weight))


def bellmanford(graph, source):
    n = graph.vertices
    # Step 1. Initialize
    dist = [float("inf")] * n
    dist[source] = 0

    # Step 2. Relax the distance
    for i in range(n - 1):
        for source, destination, weight in graph.edges:
            print(dist, source, destination)
            if (
                dist[source] != float("inf")
                and dist[destination] > dist[source] + weight
            ):
                dist[destination] = dist[source] + weight

    # Step 3. Check for negative cycle
    for source, destination, weight in graph.edges:
        if dist[destination] > dist[source] + weight:
            raise ValueError("Found negative cycle in graph")
    # Step 4. Return distances
    return dist


vertices = 5
g = Graph(vertices)

g.add_edge(1, 2, 1)
g.add_edge(2, 4, 1)
g.add_edge(0, 1, 1)
g.add_edge(3, 2, 1)

print(bellmanford(g, 0))
# [0, 1, 2, inf, 3]
