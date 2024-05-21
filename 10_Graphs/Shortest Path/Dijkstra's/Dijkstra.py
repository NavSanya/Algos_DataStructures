import heapq
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v, w):
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))  # For an undirected graph

    def dijkstra(self, src):
        pq = [(0, src)]
        dist = {node: float('inf') for node in self.graph}
        dist[src] = 0

        while pq:
            current_distance, u = heapq.heappop(pq)

            if current_distance > dist[u]:
                continue

            for v, weight in self.graph[u]:
                distance = current_distance + weight

                if distance < dist[v]:
                    dist[v] = distance
                    heapq.heappush(pq, (distance, v))

        print(f"Vertex Distance from Source ({src})")
        for node in self.graph:
            print(f"{node}\t\t{dist[node]}")

# Sample usage
g = Graph()
g.add_edge(0, 1, 9)
g.add_edge(0, 2, 6)
g.add_edge(0, 3, 5)
g.add_edge(0, 4, 3)
g.add_edge(2, 1, 2)
g.add_edge(2, 3, 4)

g.dijkstra(0)
