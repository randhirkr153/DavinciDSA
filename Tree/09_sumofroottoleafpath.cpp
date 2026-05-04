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
    int solve(TreeNode* root, int currentSum) {
        if (root == NULL) return 0;

        currentSum = currentSum * 10 + root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return currentSum;
        }

        return solve(root->left, currentSum) +
               solve(root->right, currentSum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};

int main() {
    // Example:
    //     1
    //    / \
    //   2   3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;
    cout << "Sum: " << obj.sumRootToLeaf(root) << endl;

    return 0;
}

// Paths:

// 1 → 2 = 12
// 1 → 3 = 13

// 👉 Total = 12 + 13 = 25