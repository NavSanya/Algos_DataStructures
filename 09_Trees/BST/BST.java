import java.io.*;
import java.util.*;

class BST {
    Node root;

    BST() {
        root = null;
    }

    Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        }

        return node;
    }

    Node search(Node root, int key) {
        if (root == null || root.key == key) {
            return root;
        }

        if (root.key < key) {
            return search(root.right, key);
        }

        return search(root.left, key);
    }

    public static void printTree(Node root) {
        if (root == null)
            return;
        
        Queue<Pair<Node, Integer>> queue = new ArrayDeque<>();
        queue.add(new Pair<>(root, 0));
        int prevLevel = 0;
        
        while (!queue.isEmpty()) {
            Pair<Node, Integer> pair = queue.poll();
            Node node = pair.getKey();
            int level = pair.getValue();
            
            if (level != prevLevel) {
                System.out.println();
                prevLevel = level;
            }
            
            int spaces = (int) Math.pow(2, 5 - level) - 1;
            System.out.print(" ".repeat(spaces) + node.key + " ".repeat(spaces));
            
            if (node.left != null)
                queue.add(new Pair<>(node.left, level + 1));
            if (node.right != null)
                queue.add(new Pair<>(node.right, level + 1));
        }
        System.out.println();
        
    }

    public static void main(String[] args) throws IOException {
        BST tree = new BST();
        Node root = null;
        root = tree.insert(root, 50);
        tree.insert(root, 30);
        tree.insert(root, 20);
        tree.insert(root, 40);
        tree.insert(root, 70);
        tree.insert(root, 60);
        tree.insert(root, 80);

        int key = 6;

        if (tree.search(root, key) == null) {
            System.out.println(key + " not found");
        } else {
            System.out.println(key + " found");
        }

        key = 60;

        if (tree.search(root, key) == null) {
            System.out.println(key + " not found");
        } else {
            System.out.println(key + " found");
        }

        tree.printTree(root);
    }
}

class Node {
        int key;
        Node left, right;
    
        public Node(int item) {
            key = item;
            left = right = null;
        }
}

class Pair<F, S> {
        private F first;
        private S second;
    
        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    
        public F getKey() {
            return first;
        }
    
        public S getValue() {
            return second;
        }
    
        public void setFirst(F first) {
            this.first = first;
        }
    
        public void setSecond(S second) {
            this.second = second;
        }
    }
    