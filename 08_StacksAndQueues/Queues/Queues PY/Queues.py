class Queue:
    def __init__(self):
        self.front = -1
        self.rear = -1
        self.size = 7
        self.arr = [None] * self.size

    def is_full(self):
        return self.front == 0 and self.rear == self.size - 1

    def is_empty(self):
        return self.front == -1

    def enqueue(self, val):
        if self.is_full():
            print("Full Queue")
            return
        if self.front == -1:
            self.front = 0
        self.rear += 1
        self.arr[self.rear] = val
        print(f"Added {val}")

    def dequeue(self):
        if self.is_empty():
            print("Empty Queue")
            return
        val = self.arr[self.front]
        if self.front >= self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.front += 1
        print(f"Deleted {val}")

    def display(self):
        print("-----Queue-----")
        if self.is_empty():
            print("Empty")
            return
        print("vv Front")
        for i in range(self.front, self.rear + 1):
            print(f"{i} | {self.arr[i]}")
        print("^^ Rear")


if __name__ == "__main__":
    q = Queue()

    q.enqueue(2)
    q.display()
    q.enqueue(3)
    q.enqueue(5)
    q.display()
    q.dequeue()
    q.display()
    q.enqueue(7)
    q.enqueue(1)
    q.dequeue()
    q.display()
    q.enqueue(8)
    q.enqueue(0)
    q.display()
