#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);  // For an undirected graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> setds;

        setds.insert({0, src});
        dist[src] = 0;

        while (!setds.empty()) {
            int u = setds.begin()->second;
            setds.erase(setds.begin());

            for (auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    if (dist[v] != INT_MAX)
                        setds.erase(setds.find({dist[v], v}));

                    dist[v] = dist[u] + weight;
                    setds.insert({dist[v], v});
                }
            }
        }

        cout << "Vertex Distance from Source (" << src << ")" << endl;
        for (int i = 0; i < V; ++i)
            cout << i << "\t\t" << dist[i] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 4, 3);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 4);

    g.dijkstra(0);

    return 0;
}
