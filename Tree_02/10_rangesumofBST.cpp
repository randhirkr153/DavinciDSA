#include <iostream>
using namespace std;

// Definition of TreeNode
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        // If value is smaller than range → skip left subtree
        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        // If value is greater than range → skip right subtree
        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        // If value is in range → include it
        return root->val
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};

// Helper function to insert into BST
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
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);

    Solution sol;

    int low = 7, high = 15;

    int result = sol.rangeSumBST(root, low, high);

    cout << "Range Sum BST: " << result << endl;

    return 0;
}