import java.io.*;
import java.util.*;



class BinaryTree {

    Node root;

    void inorderTraversal(Node node) {
        if (node == null)
            return;

        inorderTraversal(node.left);
        System.out.print(node.data + " ");
        inorderTraversal(node.right);
    }

    void preorderTraversal(Node node) {
        if (node == null)
            return;

        System.out.print(node.data + " ");
        preorderTraversal(node.left);
        preorderTraversal(node.right);
    }

    void postorderTraversal(Node node) {
        if (node == null)
            return;

        postorderTraversal(node.left);
        postorderTraversal(node.right);
        System.out.print(node.data + " ");
    }

    void printTree(Node root) {
        if (root == null)
            return;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;
        while (!queue.isEmpty()) {
            int nodeCount = queue.size();
            System.out.print("Level " + level + ": ");
            while (nodeCount > 0) {
                Node node = queue.poll();
                if (node != null) {
                    System.out.print(node.data + " ");
                    queue.add(node.left);
                    queue.add(node.right);
                } else {
                    System.out.print("NULL ");
                }
                nodeCount--;
            }
            System.out.println();
            level++;
        }
    }

    public static void main(String[] args) throws IOException {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("In-order Traversal:");
        tree.inorderTraversal(tree.root);
        System.out.println();

        System.out.println("Pre-order Traversal:");
        tree.preorderTraversal(tree.root);
        System.out.println();

        System.out.println("Post-order Traversal:");
        tree.postorderTraversal(tree.root);
        System.out.println();

        System.out.println("Tree Structure:");
        tree.printTree(tree.root);
    }
}

class Node {
        int data;
        Node left, right;
    
        public Node(int item) {
            data = item;
            left = right = null;
        }
    }