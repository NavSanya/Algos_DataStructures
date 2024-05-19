from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_tree(root):
    if not root:
        return

    queue = deque([(root, 0)])
    prev_level = 0
    while queue:
        node, level = queue.popleft()
        if level != prev_level:
            print()
            prev_level = level
        print(" " * (2 ** (5 - level) - 1), node.val, end=" " * (2 ** (5 - level) - 1))
        if node.left:
            queue.append((node.left, level + 1))
        if node.right:
            queue.append((node.right, level + 1))
    print()

def bfs(root):
    if not root:
        return []
    result = []
    queue = deque([root])
    while queue:
        node = queue.popleft()
        result.append(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    return result

def dfs(root):
    if not root:
        return []
    result = []
    stack = [root]
    while stack:
        node = stack.pop()
        result.append(node.val)
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    return result

# Example usage
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print("Tree Structure:")
print_tree(root)

print("BFS Traversal:", bfs(root))
print("DFS Traversal:", dfs(root))
