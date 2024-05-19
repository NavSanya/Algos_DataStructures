#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>

using namespace std;

class Node {
public:
    int key;
    Node *left, *right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        return node;
    }

    Node* search(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        if (root->key < key) {
            return search(root->right, key);
        }

        return search(root->left, key);
    }

    void printTree(Node* root) {
    if (root == nullptr)
        return;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int prevLevel = 0;
    
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        
        if (level != prevLevel) {
            cout << endl;
            prevLevel = level;
        }
        
        int spaces = pow(2, 5 - level) - 1;
        cout << string(spaces, ' ') << node->key << string(spaces, ' ');
        
        if (node->left != nullptr)
            q.push({node->left, level + 1});
        if (node->right != nullptr)
            q.push({node->right, level + 1});
    }
    cout << endl;
}
};

int main() {
    BinarySearchTree tree;
    Node* root = nullptr;
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 70);
    tree.insert(root, 60);
    tree.insert(root, 80);

    int key = 6;

    if (tree.search(root, key) == nullptr) {
        cout << key << " not found" << endl;
    } else {
        cout << key << " found" << endl;
    }

    key = 60;

    if (tree.search(root, key) == nullptr) {
        cout << key << " not found" << endl;
    } else {
        cout << key << " found" << endl;
    }

    tree.printTree(root);
    return 0;
}
