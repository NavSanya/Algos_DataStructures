class Node:
    def __init__(self, key):
        self.key = key
        self.degree = 0
        self.mark = False
        self.parent = None
        self.child = None
        self.left = self
        self.right = self

class FibonacciHeap:
    def __init__(self):
        self.min = None
        self.count = 0

    def insert(self, key):
        node = Node(key)
        if self.min is None:
            self.min = node
        else:
            self.min.left.right = node
            node.right = self.min
            node.left = self.min.left
            self.min.left = node
            if key < self.min.key:
                self.min = node
        self.count += 1

    def get_min(self):
        return self.min.key if self.min else None

    def union(self, other):
        if not other.min:
            return self
        if not self.min:
            self.min = other.min
            self.count = other.count
            return self
        self.min.right.left = other.min.left
        other.min.left.right = self.min.right
        self.min.right = other.min
        other.min.left = self.min
        if other.min.key < self.min.key:
            self.min = other.min
        self.count += other.count
        return self

    def extract_min(self):
        z = self.min
        if z:
            if z.child:
                children = [x for x in self.iterate(z.child)]
                for x in children:
                    x.left.right = x.right
                    x.right.left = x.left
                    x.left = self.min
                    x.right = self.min.right
                    self.min.right.left = x
                    self.min.right = x
                    x.parent = None
            z.left.right = z.right
            z.right.left = z.left
            if z == z.right:
                self.min = None
            else:
                self.min = z.right
                self.consolidate()
            self.count -= 1
        return z.key if z else None

    def consolidate(self):
        A = [None] * self.count
        nodes = [x for x in self.iterate(self.min)]
        for w in nodes:
            x = w
            d = x.degree
            while A[d] is not None:
                y = A[d]
                if x.key > y.key:
                    x, y = y, x
                self.link(y, x)
                A[d] = None
                d += 1
            A[d] = x
        self.min = None
        for i in range(len(A)):
            if A[i] is not None:
                if self.min is None:
                    self.min = A[i]
                else:
                    A[i].left.right = A[i].right
                    A[i].right.left = A[i].left
                    A[i].left = self.min
                    A[i].right = self.min.right
                    self.min.right.left = A[i]
                    self.min.right = A[i]
                    if A[i].key < self.min.key:
                        self.min = A[i]

    def link(self, y, x):
        y.left.right = y.right
        y.right.left = y.left
        y.parent = x
        if x.child is None:
            x.child = y
            y.right = y
            y.left = y
        else:
            y.left = x.child
            y.right = x.child.right
            x.child.right.left = y
            x.child.right = y
        x.degree += 1
        y.mark = False

    def iterate(self, head):
        node = stop = head
        flag = False
        while True:
            if node == stop and flag is True:
                break
            elif node == stop:
                flag = True
            yield node
            node = node.right

# Example usage
fh = FibonacciHeap()
fh.insert(10)
fh.insert(5)
fh.insert(20)
fh.insert(2)
fh.insert(15)

print("Minimum value:", fh.get_min()) # 2
print("Extract minimum value:", fh.extract_min()) # 2
print("New minimum value:", fh.get_min()) # 5
