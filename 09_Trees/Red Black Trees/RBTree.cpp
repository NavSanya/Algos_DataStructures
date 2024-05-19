#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

enum Color { RED, BLACK };

struct TreeNode {
    int key;
    TreeNode* left, *right, *parent;
    Color color;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};

class RedBlackTree {
public:
    TreeNode* root;
    TreeNode* NIL;

    void leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        x->right = y->left;
        if (y->left != NIL)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        y->left = x->right;
        if (x->right != NIL)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
        x->right = y;
        y->parent = x;
    }

    void insertFixup(TreeNode* z) {
        while (z != root && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                TreeNode* y = z->parent->parent->right;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                TreeNode* y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

public:
    RedBlackTree() {
        NIL = new TreeNode(-1);
        NIL->color = BLACK;
        root = NIL;
    }

    void insert(int key) {
        TreeNode* z = new TreeNode(key);
        TreeNode* y = nullptr;
        TreeNode* x = root;

        while (x != NIL) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        z->left = NIL;
        z->right = NIL;
        z->color = RED;
        insertFixup(z);
    }

    void printTree(TreeNode* root) {
        if (root == NIL)
            return;

        queue<pair<TreeNode*, int>> q;
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
            cout << string(spaces, ' ') << node->key << "(" << (node->color == RED ? "R" : "B") << ")" << string(spaces, ' ');

            if (node->left != NIL)
                q.push({node->left, level + 1});
            if (node->right != NIL)
                q.push({node->right, level + 1});
        }
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(5);
    rbt.insert(15);
    rbt.insert(3);
    rbt.insert(7);
    rbt.insert(12);
    rbt.insert(17);

    cout << "Red-Black Tree Structure:" << endl;
    rbt.printTree(rbt.root);

    return 0;
}
