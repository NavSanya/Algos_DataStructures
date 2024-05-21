import java.util.*;

class Graph {
    private int V;
    private LinkedList<Node> adj[];

    class Node implements Comparator<Node> {
        public int node;
        public int cost;

        public Node() {}

        public Node(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compare(Node node1, Node node2) {
            if (node1.cost < node2.cost)
                return -1;
            if (node1.cost > node2.cost)
                return 1;
            return 0;
        }
    }

    Graph(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList<>();
    }

    void addEdge(int u, int v, int w) {
        adj[u].add(new Node(v, w));
        adj[v].add(new Node(u, w));  // For an undirected graph
    }

    void dijkstra(int src) {
        PriorityQueue<Node> pq = new PriorityQueue<>(V, new Node());
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        pq.add(new Node(src, 0));
        dist[src] = 0;

        while (!pq.isEmpty()) {
            int u = pq.poll().node;

            for (Node edge : adj[u]) {
                int v = edge.node;
                int weight = edge.cost;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.add(new Node(v, dist[v]));
                }
            }
        }

        System.out.println("Vertex Distance from Source (" + src + ")");
        for (int i = 0; i < V; ++i)
            System.out.println(i + "\t\t" + dist[i]);
    }
    

    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1, 9);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(0, 4, 3);
        g.addEdge(2, 1, 2);
        g.addEdge(2, 3, 4);

        g.dijkstra(0);
    }
}
