from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def bfs(self, s):
        visited = set()
        queue = deque([s])
        visited.add(s)

        print(f"BFS starting from vertex {s}: ", end="")
        while queue:
            vertex = queue.popleft()
            print(vertex, end=" ")

            for neighbor in self.graph[vertex]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        print()

    def dfs_util(self, v, visited):
        visited.add(v)
        print(v, end=" ")

        for neighbor in self.graph[v]:
            if neighbor not in visited:
                self.dfs_util(neighbor, visited)

    def dfs(self, v):
        visited = set()
        print(f"DFS starting from vertex {v}: ", end="")
        self.dfs_util(v, visited)
        print()

# Sample usage
g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

g.bfs(2)
g.dfs(2)
