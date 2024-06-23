#include "CLL.hpp"

void CLL:: printList() {
        if (head == nullptr) {
            cout << "No List\n";
            return;
        }
        Node* temp = head;
        numNodes = 0;
        cout<<head->val;
        do {
            cout << "---->" << temp->val;
            temp = temp->next;
            numNodes++;
        } while (temp != head);
        cout << "\n^";
        int i  = numNodes;
        while(i > 0)
        {
                cout << "______";
                i--;
        }
        cout << "|\n";
    }

    void CLL:: printRevHelper(Node* node) {
        if (node->next != head) {
            printRevHelper(node->next);
        }
        
        cout << node->val << "---->";
        
    }

    void CLL:: printRevList() {
        if (head == nullptr) {
            cout << "No List\n";
            return;
        }
        printRevHelper(head);
        int i  = numNodes;
        cout<<head->val<<"\n^";

        while(i > 0)
        {
                cout << "______";
                i--;
        }
        cout << "|\n";
    }

    void CLL:: swap(Node* a, Node* b) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    void CLL:: addEnd(int newVal) {
        Node* nn = new Node(newVal);
        numNodes++;
        if (head == nullptr) {
            head = nn;
            tail = nn;
            nn->next = head;
        } else {
            tail->next = nn;
            tail = nn;
            tail->next = head;
        }
    }

    void CLL:: addAfter(int newVal, int prevVal) {
        Node* nn = new Node(newVal);
        if (head == nullptr) return;
        Node* temp = head;
        do {
            if (temp->val == prevVal) {
                numNodes++;
                nn->next = temp->next;
                temp->next = nn;
                if (temp == tail) {
                    tail = nn;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void CLL:: addBefore(int newVal, int nextVal) {
        Node* nn = new Node(newVal);
        if (head == nullptr) return;
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->val == nextVal) {
                numNodes++;
                if (prev == nullptr) {
                    nn->next = head;
                    head = nn;
                    tail->next = head;
                } else {
                    nn->next = prev->next;
                    prev->next = nn;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

    }

    int CLL:: deleteFirstInstance(int target) {
        if (head == nullptr) return -9999;
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->val == target) {
                numNodes--;
                if (temp == head) {
                    if (head == tail) {
                        delete head;
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        tail->next = head;
                    }
                } else {
                    prev->next = temp->next;
                    if (temp == tail) {
                        tail = prev;
                    }
                }
                int val = temp->val;
                delete temp;
                return val;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        return -9999;
    }

    void CLL:: deleteAllInstances(int target) {
        if (head == nullptr) return;
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->val == target) {
                numNodes--;
                if (temp == head) {
                    if (head == tail) {
                        delete head;
                        head = tail = nullptr;
                        return;
                    } else {
                        head = head->next;
                        tail->next = head;
                        delete temp;
                        temp = head;
                    }
                } else {
                    prev->next = temp->next;
                    if (temp == tail) {
                        tail = prev;
                    }
                    delete temp;
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        } while (temp != head);
    }

    void CLL:: deleteFront() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        numNodes--;
    }

    void CLL:: deleteEnd() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
        }
        numNodes--;
    }

int main() {
    cout << "The Circular Linked List\n";
    CLL obj;
    obj.addEnd(1);
    obj.addEnd(3);
    obj.addEnd(7);
    obj.addEnd(9);
    obj.addEnd(8);
    obj.addEnd(1);
    obj.addEnd(2);
    obj.addEnd(8);
    obj.addEnd(7);
    obj.addEnd(9);

    obj.printList();

    cout << "Add 5 after 2\n";
    obj.addAfter(5, 2);
    obj.printList();

    cout << "Add 6 before 1\n";
    obj.addBefore(6, 1);
    obj.printList();

    cout << "Delete front\n";
    obj.deleteFront();
    obj.printList();

    cout << "Delete end\n";
    obj.deleteEnd();
    obj.printList();

    cout << "Delete the first instance of 2\n";
    obj.deleteFirstInstance(2);
    obj.printList();

    cout << "Delete all instances of 8\n";
    obj.deleteAllInstances(8);
    obj.printList();

    cout << "Print List in Reverse\n";
    obj.printRevList();

    return 0;
}