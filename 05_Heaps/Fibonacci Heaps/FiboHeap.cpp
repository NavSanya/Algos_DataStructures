#include <iostream>
#include <vector>
#include <cmath>

class Node {
public:
    int key;
    int degree = 0;
    Node* parent = nullptr;
    Node* child = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    bool mark = false;

    Node(int k) : key(k) {
        left = this;
        right = this;
    }
};

class FibonacciHeap {
private:
    Node* min = nullptr;
    int count = 0;

    std::vector<Node*> getChildren(Node* head) {
        std::vector<Node*> children;
        Node* node = head;
        do {
            children.push_back(node);
            node = node->right;
        } while (node != head);
        return children;
    }

    void link(Node* y, Node* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->right = y;
            y->left = y;
        } else {
            y->left = x->child;
            y->right = x->child->right;
            x->child->right->left = y;
            x->child->right = y;
        }
        x->degree++;
        y->mark = false;
    }

    void consolidate() {
        std::vector<Node*> A(count, nullptr);
        std::vector<Node*> nodes = getChildren(min);
        for (Node* w : nodes) {
            Node* x = w;
            int d = x->degree;
            while (A[d] != nullptr) {
                Node* y = A[d];
                if (x->key > y->key) {
                    std::swap(x, y);
                }
                link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
        }
        min = nullptr;
        for (Node* a : A) {
            if (a != nullptr) {
                if (min == nullptr) {
                    min = a;
                } else {
                    a->left->right = a->right;
                    a->right->left = a->left;
                    a->left = min;
                    a->right = min->right;
                    min->right->left = a;
                    min->right = a;
                    if (a->key < min->key) {
                        min = a;
                    }
                }
            }
        }
    }

public:
    void insert(int key) {
        Node* node = new Node(key);
        if (min == nullptr) {
            min = node;
        } else {
            min->left->right = node;
            node->right = min;
            node->left = min->left;
            min->left = node;
            if (key < min->key) {
                min = node;
            }
        }
        count++;
    }

    int getMin() {
        return min ? min->key : -1;
    }

    int extractMin() {
        Node* z = min;
        if (z != nullptr) {
            if (z->child != nullptr) {
                std::vector<Node*> children = getChildren(z->child);
                for (Node* x : children) {
                    x->left->right = x->right;
                    x->right->left = x->left;
                    x->left = min;
                    x->right = min->right;
                    min->right->left = x;
                    min->right = x;
                    x->parent = nullptr;
                }
            }
            z->left->right = z->right;
            z->right->left = z->left;
            if (z == z->right) {
                min = nullptr;
            } else {
                min = z->right;
                consolidate();
            }
            count--;
        }
        return z ? z->key : -1;
    }

    void unionHeap(FibonacciHeap& other) {
        if (other.min == nullptr) {
            return;
        }
        if (min == nullptr) {
            min = other.min;
            count = other.count;
            return;
        }
        min->right->left = other.min->left;
        other.min->left->right = min->right;
        min->right = other.min;
        other.min->left = min;
        if (other.min->key < min->key) {
            min = other.min;
        }
        count += other.count;
    }
};

int main() {
    FibonacciHeap fh;
    fh.insert(10);
    fh.insert(5);
    fh.insert(20);
    fh.insert(2);
    fh.insert(15);

    std::cout << "Minimum value: " << fh.getMin() << std::endl; // 2
    std::cout << "Extract Minimum value: " << fh.extractMin() << std::endl; // 2
    std::cout << "Minimum value: " << fh.getMin() << std::endl; // 5

}