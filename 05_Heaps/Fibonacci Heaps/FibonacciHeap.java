import java.util.ArrayList;
import java.util.List;


class FibonacciHeap {
    private Node min;
    private int count = 0;

    public void insert(int key) {
        Node node = new Node(key);
        if (min == null) {
            min = node;
        } else {
            min.left.right = node;
            node.right = min;
            node.left = min.left;
            min.left = node;
            if (key < min.key) {
                min = node;
            }
        }
        count++;
    }

    public int getMin() {
        return min != null ? min.key : -1;
    }

    public void union(FibonacciHeap other) {
        if (other.min == null) {
            return;
        }
        if (min == null) {
            min = other.min;
            count = other.count;
            return;
        }
        min.right.left = other.min.left;
        other.min.left.right = min.right;
        min.right = other.min;
        other.min.left = min;
        if (other.min.key < min.key) {
            min = other.min;
        }
        count += other.count;
    }

    public int extractMin() {
        Node z = min;
        if (z != null) {
            if (z.child != null) {
                List<Node> children = getChildren(z.child);
                for (Node x : children) {
                    x.left.right = x.right;
                    x.right.left = x.left;
                    x.left = min;
                    x.right = min.right;
                    min.right.left = x;
                    min.right = x;
                    x.parent = null;
                }
            }
            z.left.right = z.right;
            z.right.left = z.left;
            if (z == z.right) {
                min = null;
            } else {
                min = z.right;
                consolidate();
            }
            count--;
        }
        return z != null ? z.key : -1;
    }

    private void consolidate() {
        List<Node> A = new ArrayList<>(count);
        for (int i = 0; i < count; i++) {
            A.add(null);
        }
        List<Node> nodes = getChildren(min);
        for (Node w : nodes) {
            Node x = w;
            int d = x.degree;
            while (A.get(d) != null) {
                Node y = A.get(d);
                if (x.key > y.key) {
                    Node temp = x;
                    x = y;
                    y = temp;
                }
                link(y, x);
                A.set(d, null);
                d++;
            }
            A.set(d, x);
        }
        min = null;
        for (Node a : A) {
            if (a != null) {
                if (min == null) {
                    min = a;
                } else {
                    a.left.right = a.right;
                    a.right.left = a.left;
                    a.left = min;
                    a.right = min.right;
                    min.right.left = a;
                    min.right = a;
                    if (a.key < min.key) {
                        min = a;
                    }
                }
            }
        }
    }

    private void link(Node y, Node x) {
        y.left.right = y.right;
        y.right.left = y.left;
        y.parent = x;
        if (x.child == null) {
            x.child = y;
            y.right = y;
            y.left = y;
        } else {
            y.left = x.child;
            y.right = x.child.right;
            x.child.right.left = y;
            x.child.right = y;
        }
        x.degree++;
        y.mark = false;
    }

    private List<Node> getChildren(Node head) {
        List<Node> children = new ArrayList<>();
        Node node = head;
        do {
            children.add(node);
            node = node.right;
        } while (node != head);
        return children;
    }

    public static void main(String[] args) {
        FibonacciHeap fh = new FibonacciHeap();
        fh.insert(10);
        fh.insert(5);
        fh.insert(20);
        fh.insert(2);
        fh.insert(15);

        System.out.println("Minimum value: " + fh.getMin()); // 2
        System.out.println("Extract minimum value: " + fh.extractMin()); // 2
        System.out.println("New minimum value: " + fh.getMin()); // 5
    }
}

class Node {
        int key;
        int degree = 0;
        Node parent;
        Node child;
        Node left;
        Node right;
        boolean mark = false;
    
        Node(int key) {
            this.key = key;
            this.left = this;
            this.right = this;
        }
    }
    