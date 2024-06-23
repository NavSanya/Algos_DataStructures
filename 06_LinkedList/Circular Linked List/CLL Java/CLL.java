
class CLL {
private NodeCLL head;
private NodeCLL tail;
private int numNodes;


CLL() {
        this.head = null;
        this.tail = null;
        this.numNodes = 0;
}

void printList() {
        if (head == null) {
            System.out.println("No List");
            return;
        }
        NodeCLL temp = head;
        numNodes = 0;
        System.out.print(head.val);
        do {
            System.out.print("---->" + temp.val);
            temp = temp.next;
            numNodes++;
        } while (temp != head);
        System.out.println("\n^");
        for (int i = numNodes; i > 0; i--) {
            System.out.print("______");
        }
        System.out.println("|");
    }

    void printRevHelper(NodeCLL node) {
        if (node.next != head) {
            printRevHelper(node.next);
        }
        System.out.print(node.val + "---->");
    }

    void printRevList() {
        if (head == null) {
            System.out.println("No List");
            return;
        }
        printRevHelper(head);
        System.out.print(head.val + "\n^");
        for (int i = numNodes; i > 0; i--) {
            System.out.print("______");
        }
        System.out.println("|");
    }


void swap(NodeCLL a, NodeCLL b) {
        int temp = a.val;
        a.val = b.val;
        b.val = temp;
}

void addEnd(int newVal) {
        NodeCLL nn = new NodeCLL(newVal);
        if (head == null) {
        head = nn;
        tail = nn;
        nn.next = head;
        } else {
        tail.next = nn;
        tail = nn;
        tail.next = head;
        }
}

void addAfter(int newVal, int prevVal) {
        NodeCLL nn = new NodeCLL(newVal);
        if (head == null) return;
        NodeCLL temp = head;
        do {
        if (temp.val == prevVal) {
                nn.next = temp.next;
                temp.next = nn;
                if (temp == tail) {
                tail = nn;
                }
                return;
        }
        temp = temp.next;
        } while (temp != head);
}

void addBefore(int newVal, int nextVal) {
        NodeCLL nn = new NodeCLL(newVal);
        if (head == null) return;
        NodeCLL temp = head;
        NodeCLL prev = null;
        do {
        if (temp.val == nextVal) {
                if (prev == null) {
                nn.next = head;
                head = nn;
                tail.next = head;
                } else {
                nn.next = prev.next;
                prev.next = nn;
                }
                return;
        }
        prev = temp;
        temp = temp.next;
        } while (temp != head);
}

int deleteFirstInstance(int target) {
        if (head == null) return -9999;
        NodeCLL temp = head;
        NodeCLL prev = null;
        do {
        if (temp.val == target) {
                if (temp == head) {
                if (head == tail) {
                        head = tail = null;
                } else {
                        head = head.next;
                        tail.next = head;
                }
                } else {
                prev.next = temp.next;
                if (temp == tail) {
                        tail = prev;
                }
                }
                return temp.val;
        }
        prev = temp;
        temp = temp.next;
        } while (temp != head);
        return -9999;
}

void deleteAllInstances(int target) {
        if (head == null) return;
        NodeCLL temp = head;
        NodeCLL prev = null;
        do {
        if (temp.val == target) {
                if (temp == head) {
                if (head == tail) {
                        head = tail = null;
                        return;
                } else {
                        head = head.next;
                        tail.next = head;
                }
                } else {
                prev.next = temp.next;
                if (temp == tail) {
                        tail = prev;
                }
                }
        } else {
                prev = temp;
        }
        temp = temp.next;
        } while (temp != head);
}

void deleteFront() {
        if (head == null) return;
        if (head == tail) {
        head = tail = null;
        } else {
        head = head.next;
        tail.next = head;
        }
}

void deleteEnd() {
        if (head == null) return;
        if (head == tail) {
        head = tail = null;
        } else {
        NodeCLL temp = head;
        while (temp.next != tail) {
                temp = temp.next;
        }
        tail = temp;
        tail.next = head;
        }
}

public static void main(String[] args) {
        System.out.println("The Circular Linked List");
        CLL obj = new CLL();
        obj.addEnd(1);
        obj.addEnd(2);
        obj.addEnd(3);
        obj.addEnd(4);
        obj.printList();

        System.out.println("Add 5 after 2");
        obj.addAfter(5, 2);
        obj.printList();

        System.out.println("Add 6 before 1");
        obj.addBefore(6, 1);
        obj.printList();

        System.out.println("Delete front");
        obj.deleteFront();
        obj.printList();

        System.out.println("Delete end");
        obj.deleteEnd();
        obj.printList();

        System.out.println("Delete the first instance of 2");
        obj.deleteFirstInstance(2);
        obj.printList();

        System.out.println("Delete all instances of 5");
        obj.deleteAllInstances(5);
        obj.printList();

        System.out.println("Print List in Reverse");
        obj.printRevList();
}
}
