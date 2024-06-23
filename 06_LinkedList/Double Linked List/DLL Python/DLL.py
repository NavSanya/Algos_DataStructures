class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

class DLL:
    def __init__(self, head=None):
        self.head = head
        self.tail = head

    def print_list(self):
        if self.head is None:
            print("No List")
            return
        temp = self.head
        while temp != self.tail:
            print(temp.val, end="<---->")
            temp = temp.next
        print(temp.val)

    def print_rev_list(self):
        if self.tail is None:
            print("No List")
            return
        temp = self.tail
        while temp.prev is not None:
            print(temp.val, end="<---->")
            temp = temp.prev
        print(temp.val)

    def add_end(self, new_val):
        nn = Node(new_val)
        if self.head is None:
            self.head = nn
            self.tail = nn
            return
        temp = self.tail
        nn.prev = temp
        temp.next = nn
        self.tail = nn

    def add_after(self, new_val, prev_val):
        nn = Node(new_val)
        if self.head is None:
            return
        temp_start = self.head
        while temp_start.next is not None and temp_start.val != prev_val:
            temp_start = temp_start.next

        if temp_start is None or temp_start.val != prev_val:
            print("Value not found")
            return

        new_next = temp_start.next
        temp_start.next = nn
        nn.next = new_next
        nn.prev = temp_start
        if new_next is not None:
            new_next.prev = nn
        if temp_start == self.tail:
            self.tail = nn

    def add_before(self, new_val, next_val):
        nn = Node(new_val)
        if self.head is None:
            return
        temp_end = self.tail
        while temp_end.prev is not None and temp_end.val != next_val:
            temp_end = temp_end.prev

        if temp_end is None or temp_end.val != next_val:
            print("Not Present")
            return

        nn.prev = temp_end.prev
        if temp_end.prev is not None:
            temp_end.prev.next = nn
        temp_end.prev = nn
        nn.next = temp_end
        if temp_end == self.head:
            self.head = nn

    def delete_first_instance(self, target):
        if self.head is None:
            return -9999

        temp = self.head
        while temp is not None and temp.val != target:
            temp = temp.next

        if temp is None:
            print("Not Present")
            return -9999

        if temp.prev is not None:
            temp.prev.next = temp.next
        else:
            self.head = temp.next

        if temp.next is not None:
            temp.next.prev = temp.prev
        else:
            self.tail = temp.prev

        return temp.val

    def delete_all_instances(self, target):
        if self.head is None:
            return

        temp = self.head
        while temp is not None:
            if temp.val == target:
                if temp == self.head:
                    self.head = self.head.next
                    if self.head is not None:
                        self.head.prev = None
                else:
                    temp.prev.next = temp.next
                    if temp.next is not None:
                        temp.next.prev = temp.prev
                    else:
                        self.tail = temp.prev
            temp = temp.next

    def delete_front(self):
        if self.head is None:
            return
        self.head = self.head.next
        if self.head is not None:
            self.head.prev = None
        else:
            self.tail = None

    def delete_end(self):
        if self.tail is None:
            return
        self.tail = self.tail.prev
        if self.tail is not None:
            self.tail.next = None
        else:
            self.head = None

    def swap(self, a, b):
        a.val, b.val = b.val, a.val

    def sort_dll(self):
        if self.head is None:
            return

        i = self.head
        while i != self.tail:
            j = i.next
            while j is not None:
                if i.val > j.val:
                    self.swap(i, j)
                j = j.next
            i = i.next


def main():
    print("The Double Linked List")
    obj = DLL()
    obj.add_end(7)
    obj.add_end(9)
    obj.add_end(10)
    obj.add_end(1)
    obj.add_end(0)
    obj.add_end(9)
    obj.add_end(2)
    obj.add_end(4)
    obj.print_list()
    print("Reverse List")
    obj.print_rev_list()

    print("Add 10 after 7")
    obj.add_after(10, 7)
    obj.print_list()

    print("Add 3 before 9")
    obj.add_before(3, 9)
    obj.print_list()

    print("Delete front")
    obj.delete_front()
    obj.print_list()

    print("Delete end")
    obj.delete_end()
    obj.print_list()

    print("Delete the first instance of 9")
    obj.delete_first_instance(9)
    obj.print_list()

    print("Delete all instances of 10")
    obj.delete_all_instances(10)
    obj.print_list()

    print("Sort List")
    obj.sort_dll()
    obj.print_list()


if __name__ == "__main__":
    main()
