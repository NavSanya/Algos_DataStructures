import java.util.ArrayDeque;
import java.util.Queue;


public class RBTree {
    private TreeNode root;
    private final TreeNode NIL;

    public RBTree() {
        NIL = new TreeNode(-1);
        NIL.color = Color.BLACK;
        root = NIL;
    }

    private void leftRotate(TreeNode x) {
        TreeNode y = x.right;
        x.right = y.left;
        if (y.left != NIL)
            y.left.parent = x;
        y.parent = x.parent;
        if (x.parent == null)
            root = y;
        else if (x == x.parent.left)
            x.parent.left = y;
        else
            x.parent.right = y;
        y.left = x;
        x.parent = y;
    }

    private void rightRotate(TreeNode y) {
        TreeNode x = y.left;
        y.left = x.right;
        if (x.right != NIL)
            x.right.parent = y;
        x.parent = y.parent;
        if (y.parent == null)
            root = x;
        else if (y == y.parent.right)
            y.parent.right = x;
        else
            y.parent.left = x;
        x.right = y;
        y.parent = x;
    }

    private void insertFixup(TreeNode z) {
        while (z != root && z.parent.color == Color.RED) {
            if (z.parent == z.parent.parent.left) {
                TreeNode y = z.parent.parent.right;
                if (y.color == Color.RED) {
                    z.parent.color = Color.BLACK;
                    y.color = Color.BLACK;
                    z.parent.parent.color = Color.RED;
                    z = z.parent.parent;
                } else {
                    if (z == z.parent.right) {
                        z = z.parent;
                        leftRotate(z);
                    }
                    z.parent.color = Color.BLACK;
                    z.parent.parent.color = Color.RED;
                    rightRotate(z.parent.parent);
                }
            } else {
                TreeNode y = z.parent.parent.left;
                if (y.color == Color.RED) {
                    z.parent.color = Color.BLACK;
                    y.color = Color.BLACK;
                    z.parent.parent.color = Color.RED;
                    z = z.parent.parent;
                } else {
                    if (z == z.parent.left) {
                        z = z.parent;
                        rightRotate(z);
                    }
                    z.parent.color = Color.BLACK;
                    z.parent.parent.color = Color.RED;
                    leftRotate(z.parent.parent);
                }
            }
        }
        root.color = Color.BLACK;
    }

    public void insert(int key) {
        TreeNode z = new TreeNode(key);
        TreeNode y = null;
        TreeNode x = root;

        while (x != NIL) {
            y = x;
            if (z.key < x.key)
                x = x.left;
            else
                x = x.right;
        }
        z.parent = y;
        if (y == null)
            root = z;
        else if (z.key < y.key)
            y.left = z;
        else
            y.right = z;
        z.left = NIL;
        z.right = NIL;
        z.color = Color.RED;
        insertFixup(z);
    }

    public void printTree(TreeNode root) {
        if (root == NIL)
            return;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int prevLevel = 0;

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == NIL)
                continue;

            int level = getLevel(node);

            if (level != prevLevel) {
                System.out.println();
                prevLevel = level;
            }

            int spaces = (int) Math.pow(2, 5 - level) - 1;
            String padding = " ".repeat(spaces);
            System.out.print(padding + node.key + "(" + (node.color == Color.RED ? "R" : "B") + ")" + padding);

            queue.add(node.left);
            queue.add(node.right);
        }
        System.out.println();
    }

    private int getLevel(TreeNode node) {
        int level = 0;
        while (node.parent != null) {
            level++;
            node = node.parent;
        }
        return level;
    }

    public static void main(String[] args) {
        RBTree rbt = new RBTree();
        rbt.insert(10);
        rbt.insert(5);
        rbt.insert(15);
        rbt.insert(3);
        rbt.insert(7);
        rbt.insert(12);
        rbt.insert(17);

        System.out.println("Red-Black Tree Structure:");
        rbt.printTree(rbt.root);
    }
}

enum Color { RED, BLACK }

class TreeNode {
        int key;
        TreeNode left, right, parent;
        Color color;
    
        TreeNode(int k) {
            key = k;
            left = right = parent = null;
            color = Color.RED;
        }
    }
    