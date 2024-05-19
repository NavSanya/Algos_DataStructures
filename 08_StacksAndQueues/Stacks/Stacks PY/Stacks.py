class Stack:
    def __init__(self):
        self.top = -1
        self.size = 7
        self.arr = [None] * self.size

    def is_full(self):
        return self.top == self.size - 1

    def is_empty(self):
        return self.top == -1

    def push(self, val):
        if self.is_full():
            print("Full Stack")
            return
        self.top += 1
        self.arr[self.top] = val
        print(f"Pushed {val}")

    def pop(self):
        if self.is_empty():
            print("Empty Stack")
            return
        val = self.arr[self.top]
        self.top -= 1
        print(f"Popped {val}")

    def display(self):
        print("-----Stack-----")
        if self.is_empty():
            print("Empty")
            return
        for i in range(self.top, -1, -1):
            print(self.arr[i])

if __name__ == "__main__":
    s = Stack()

    s.push(2)
    s.display()
    s.push(3)
    s.push(5)
    s.display()
    s.pop()
    s.display()
    s.push(7)
    s.push(1)
    s.pop()
    s.display()
    s.push(8)
    s.push(0)
    s.display()
