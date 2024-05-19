#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode* root) {
    if (root == nullptr)
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
        cout << string(spaces, ' ') << node->val << string(spaces, ' ');
        
        if (node->left != nullptr)
            q.push({node->left, level + 1});
        if (node->right != nullptr)
            q.push({node->right, level + 1});
    }
    cout << endl;
}
void bfs(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

void dfs(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Tree Structure:" << endl;
    printTree(root);

    cout << "BFS Traversal: ";
    bfs(root);

    cout << "DFS Traversal: ";
    dfs(root);

    return 0;
}