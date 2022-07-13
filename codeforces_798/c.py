from sys import stdin
from collections import defaultdict


class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(1, size+1)]
        self.rank = [0] * size
        self.connected_components = 0


    def find(self, x):
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.root[root_x] = root_y
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1
                self.connected_components += 1



t = int(input())

while t:

    n = int(input())

    adjacency_list = defaultdict(list)

    for i in range(n-1):
        source, destination = list(map(int, stdin.readline().split()))
        adjacency_list[source].append(destination)


    # Union these suckers based on DFS starting at adjacency_list[1][0] and adjacency_list[1][1]
    # It only has two children.
    left_child = adjacency_list[1][0]
    right_child = None
    
    if len(adjacency_list[1]) > 1:
        right_child = adjacency_list[1][1]

    # This will be the children of the root.
    left_tree = UnionFind(n)
    right_tree = UnionFind(n)
    # Now need to perform DFS to connect all nodes

    for node in adjacency_list[left_child]:
        print(node)
        

    
    



    t -= 1

