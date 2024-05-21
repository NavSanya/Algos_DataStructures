import java.util.*;

class Graph {
    class Edge {
        int src, dest, weight;
        Edge() {
            src = dest = weight = 0;
        }
    }

    private int V, E;
    private Edge edge[];

    Graph(int v, int e) {
        V = v;
        E = e;
        edge = new Edge[e];
        for (int i = 0; i < e; ++i)
            edge[i] = new Edge();
    }

    void addEdge(int u, int v, int w, int i) {
        edge[i].src = u;
        edge[i].dest = v;
        edge[i].weight = w;
    }

    void bellmanFord(int src) {
        int dist[] = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        for (int i = 1; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = edge[j].src;
                int v = edge[j].dest;
                int weight = edge[j].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (int j = 0; j < E; ++j) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
                System.out.println("Graph contains negative weight cycle");
        }

        System.out.println("Vertex Distance from Source (" + src + ")");
        for (int i = 0; i < V; ++i)
            System.out.println(i + "\t\t" + dist[i]);
    }

    public static void main(String[] args) {
        Graph g = new Graph(5, 8);
        g.addEdge(0, 1, -1, 0);
        g.addEdge(0, 2, 4, 1);
        g.addEdge(1, 2, 3, 2);
        g.addEdge(1, 3, 2, 3);
        g.addEdge(1, 4, 2, 4);
        g.addEdge(3, 2, 5, 5);
        g.addEdge(3, 1, 1, 6);
        g.addEdge(4, 3, -3, 7);

        g.bellmanFord(0);
    }
}
