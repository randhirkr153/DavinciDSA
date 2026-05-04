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
    int helper(TreeNode* root, bool isLeft) {
        if (root == NULL) return 0;

        // Check if it's a left leaf
        if (root->left == NULL && root->right == NULL && isLeft) {
            return root->val;
        }

        return helper(root->left, true) +
               helper(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};

int main() {
    // Example:
    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Sum of Left Leaves: " << obj.sumOfLeftLeaves(root) << endl;

    return 0;
}