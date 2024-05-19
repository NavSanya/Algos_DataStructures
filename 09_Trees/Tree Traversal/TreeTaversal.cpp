#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void printTree(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int nodeCount = q.size();
        cout << "Level " << level << ": ";
        while (nodeCount > 0) {
            Node* node = q.front();
            q.pop();
            if (node != nullptr) {
                cout << node->data << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "NULL ";
            }
            nodeCount--;
        }
        cout << endl;
        level++;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Tree Structure:\n";
    printTree(root);

    return 0;
}
