#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int v) : V(v) {
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        cout << "BFS starting from vertex " << s << ": ";
        while (!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for (auto adj_vertex : adj[s]) {
                if (!visited[adj_vertex]) {
                    visited[adj_vertex] = true;
                    q.push(adj_vertex);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto adj_vertex : adj[v])
            if (!visited[adj_vertex])
                DFSUtil(adj_vertex, visited);
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        cout << "DFS starting from vertex " << v << ": ";
        DFSUtil(v, visited);
        cout << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    g.DFS(2);

    return 0;
}
