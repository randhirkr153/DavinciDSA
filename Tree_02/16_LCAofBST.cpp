#include <iostream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        // If both nodes are smaller → go left
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both nodes are greater → go right
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise, this is the LCA
        return root;
    }
};

// Insert helper
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int main() {
    TreeNode* root = NULL;

    // Build BST
    root = insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);
    insert(root, 3);
    insert(root, 5);

    Solution sol;

    TreeNode* p = root->left;        // 2
    TreeNode* q = root->left->right; // 4

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA: " << lca->val << endl;

    return 0;
}