class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def inorder_traversal(root):
    if root is None:
        return
    inorder_traversal(root.left)
    print(root.data, end=' ')
    inorder_traversal(root.right)

def preorder_traversal(root):
    if root is None:
        return
    print(root.data, end=' ')
    preorder_traversal(root.left)
    preorder_traversal(root.right)

def postorder_traversal(root):
    if root is None:
        return
    postorder_traversal(root.left)
    postorder_traversal(root.right)
    print(root.data, end=' ')

def print_tree(root):
    if root is None:
        return
    queue = [root]
    level = 0
    while queue:
        print("Level {}: ".format(level), end='')
        for _ in range(len(queue)):
            node = queue.pop(0)
            if node:
                print(node.data, end=' ')
                queue.append(node.left)
                queue.append(node.right)
            else:
                print("NULL", end=' ')
        print()
        level += 1

# Example usage
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("In-order Traversal:", end=' ')
inorder_traversal(root)
print()

print("Pre-order Traversal:", end=' ')
preorder_traversal(root)
print()

print("Post-order Traversal:", end=' ')
postorder_traversal(root)
print()

print("Tree Structure:")
print_tree(root)
