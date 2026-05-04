#include <iostream>
#include <climits>
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
    bool isBST(TreeNode* root, long &prev) {
        if (root == NULL) return true;

        // Check left subtree
        if (!isBST(root->left, prev)) return false;

        // Current node check
        if (root->val <= prev) return false;

        prev = root->val;

        // Check right subtree
        return isBST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return isBST(root, prev);
    }
};

// Helper: Insert into BST
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

    // Valid BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);

    Solution sol;

    if (sol.isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Not a BST" << endl;

    return 0;
}