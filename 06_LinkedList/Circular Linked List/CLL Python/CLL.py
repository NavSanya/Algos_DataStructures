class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class CLL:
    def __init__(self):
        self.head = None
        self.tail = None
        self.num_nodes = 0

    def print_list(self):
        if self.head is None:
            print("No List")
            return
        temp = self.head
        print(temp.val, end="")
        self.num_nodes = 1
        temp = temp.next
        while temp != self.head:
            print("---->" + str(temp.val), end="")
            temp = temp.next
            self.num_nodes += 1
        print("\n^", end="")
        for _ in range(self.num_nodes):
            print("_____", end="")
        print("|")

    def print_rev_helper(self, node):
        if node.next.next != self.head:
            self.print_rev_helper(node.next)
        print(node.val, end="---->")

    def print_rev_list(self):
        if self.head is None:
            print("No List")
            return
        self.print_rev_helper(self.head)
        print(self.head.val)
        print("^", end="")
        for _ in range(self.num_nodes - 1):
            print("______", end="")
        print("|")

    def swap(self, a, b):
        a.val, b.val = b.val, a.val

    def add_end(self, new_val):
        nn = Node(new_val)
        if self.head is None:
            self.head = self.tail = nn
            nn.next = self.head
        else:
            self.tail.next = nn
            self.tail = nn
            self.tail.next = self.head

    def add_after(self, new_val, prev_val):
        nn = Node(new_val)
        if self.head is None:
            return
        temp = self.head
        while True:
            if temp.val == prev_val:
                nn.next = temp.next
                temp.next = nn
                if temp == self.tail:
                    self.tail = nn
                return
            temp = temp.next
            if temp == self.head:
                break

    def add_before(self, new_val, next_val):
        nn = Node(new_val)
        if self.head is None:
            return
        temp = self.head
        prev = None
        while True:
            if temp.val == next_val:
                if prev is None:
                    nn.next = self.head
                    self.head = nn
                    self.tail.next = self.head
                else:
                    nn.next = prev.next
                    prev.next = nn
                return
            prev = temp
            temp = temp.next
            if temp == self.head:
                break

    def delete_first_instance(self, target):
        if self.head is None:
            return -9999
        temp = self.head
        prev = None
        while True:
            if temp.val == target:
                if temp == self.head:
                    if self.head == self.tail:
                        self.head = self.tail = None
                    else:
                        self.head = self.head.next
                        self.tail.next = self.head
                else:
                    prev.next = temp.next
                    if temp == self.tail:
                        self.tail = prev
                return temp.val
            prev = temp
            temp = temp.next
            if temp == self.head:
                break
        return -9999

    def delete_all_instances(self, target):
        if self.head is None:
            return
        temp = self.head
        prev = None
        while True:
            if temp.val == target:
                if temp == self.head:
                    if self.head == self.tail:
                        self.head = self.tail = None
                        return
                    else:
                        self.head = self.head.next
                        self.tail.next = self.head
                        temp = self.head
                else:
                    prev.next = temp.next
                    if temp == self.tail:
                        self.tail = prev
                    temp = prev.next
            else:
                prev = temp
                temp = temp.next
            if temp == self.head:
                break

    def delete_front(self):
        if self.head is None:
            return
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.tail.next = self.head

    def delete_end(self):
        if self.head is None:
            return
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            temp = self.head
            while temp.next != self.tail:
                temp = temp.next
            self.tail = temp
            self.tail.next = self.head

def main():
    print("The Circular Linked List")
    obj = CLL()
    obj.add_end(7)
    obj.add_end(9)
    obj.add_end(10)
    obj.add_end(1)
    obj.add_end(0)
    obj.add_end(9)
    obj.add_end(2)
    obj.add_end(4)
    obj.print_list()

    print("Add 5 after 2")
    obj.add_after(5, 2)
    obj.print_list()

    print("Add 6 before 1")
    obj.add_before(6, 1)
    obj.print_list()

    print("Delete front")
    obj.delete_front()
    obj.print_list()

    print("Delete end")
    obj.delete_end()
    obj.print_list()

    print("Delete the first instance of 2")
    obj.delete_first_instance(2)
    obj.print_list()

    print("Delete all instances of 5")
    obj.delete_all_instances(5)
    obj.print_list()

    print("Print List in Reverse")
    obj.print_rev_list()

if __name__ == "__main__":
    main()
