#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    int V;
    vector<tuple<int, int, int>> edges;

public:
    Graph(int v) : V(v) {}

    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 1; i < V; ++i) {
            for (auto &[u, v, w] : edges) {
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (auto &[u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }

        cout << "Vertex Distance from Source (" << src << ")" << endl;
        for (int i = 0; i < V; ++i)
            cout << i << "\t\t" << dist[i] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}
