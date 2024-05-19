import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;


public class BFS_DFS {

    public static void printTree(TreeNode root) {
        if (root == null)
            return;
        
        Queue<Pair<TreeNode, Integer>> queue = new ArrayDeque<>();
        queue.add(new Pair<>(root, 0));
        int prevLevel = 0;
        
        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.poll();
            TreeNode node = pair.getKey();
            int level = pair.getValue();
            
            if (level != prevLevel) {
                System.out.println();
                prevLevel = level;
            }
            
            int spaces = (int) Math.pow(2, 5 - level) - 1;
            System.out.print(" ".repeat(spaces) + node.val + " ".repeat(spaces));
            
            if (node.left != null)
                queue.add(new Pair<>(node.left, level + 1));
            if (node.right != null)
                queue.add(new Pair<>(node.right, level + 1));
        }
        System.out.println();
        
    }

    public static void bfs(TreeNode root) {
        if (root == null)
            return;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            System.out.print(node.val + " ");
            if (node.left != null)
                queue.add(node.left);
            if (node.right != null)
                queue.add(node.right);
        }
        System.out.println();
    }

    public static void dfs(TreeNode root) {
        if (root == null)
            return;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            System.out.print(node.val + " ");
            if (node.right != null)
                stack.push(node.right);
            if (node.left != null)
                stack.push(node.left);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println("Tree Structure:");
        printTree(root);

        System.out.print("BFS Traversal: ");
        bfs(root);

        System.out.print("DFS Traversal: ");
        dfs(root);
    }
}

class TreeNode {
        int val;
        TreeNode left, right;
    
        public TreeNode(int val) {
            this.val = val;
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
    