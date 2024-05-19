from collections import deque

class TreeNode:
    def __init__(self, key, color="RED"):
        self.key = key
        self.left = None
        self.right = None
        self.color = color

class RedBlackTree:
    def __init__(self):
        self.NIL = TreeNode(None, "BLACK")
        self.root = self.NIL

    def insert(self, key):
        new_node = TreeNode(key)
        new_node.left = self.NIL
        new_node.right = self.NIL

        parent = None
        current = self.root
        while current != self.NIL:
            parent = current
            if new_node.key < current.key:
                current = current.left
            else:
                current = current.right

        new_node.parent = parent
        if parent is None:
            self.root = new_node
        elif new_node.key < parent.key:
            parent.left = new_node
        else:
            parent.right = new_node

        new_node.color = "RED"
        self.insert_fixup(new_node)

    def insert_fixup(self, node):
        while node != self.root and node.parent.color == "RED":
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right
                if uncle.color == "RED":
                    node.parent.color = "BLACK"
                    uncle.color = "BLACK"
                    node.parent.parent.color = "RED"
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.color = "BLACK"
                    node.parent.parent.color = "RED"
                    self.right_rotate(node.parent.parent)
            else:
                uncle = node.parent.parent.left
                if uncle.color == "RED":
                    node.parent.color = "BLACK"
                    uncle.color = "BLACK"
                    node.parent.parent.color = "RED"
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.color = "BLACK"
                    node.parent.parent.color = "RED"
                    self.left_rotate(node.parent.parent)

        self.root.color = "BLACK"

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.NIL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, y):
        x = y.left
        y.left = x.right
        if x.right != self.NIL:
            x.right.parent = y
        x.parent = y.parent
        if y.parent is None:
            self.root = x
        elif y == y.parent.right:
            y.parent.right = x
        else:
            y.parent.left = x
        x.right = y
        y.parent = x

    def print_tree(self):
        if not self.root:
            return

        queue = deque([(self.root, 0)])
        prev_level = 0
        while queue:
            node, level = queue.popleft()
            if level != prev_level:
                print()
                prev_level = level
            color = "R" if node.color == "RED" else "B"
            print(" " * (2 ** (5 - level) - 1), f"{node.key}({color})", end=" " * (2 ** (5 - level) - 1))
            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))
        print()

# Example usage
rbt = RedBlackTree()
rbt.insert(10)
rbt.insert(5)
rbt.insert(15)
rbt.insert(3)
rbt.insert(7)
rbt.insert(12)
rbt.insert(17)

print("Red-Black Tree Structure:")
rbt.print_tree()
