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
    bool isSame(TreeNode* root, int val) {
        if (root == NULL) return true;

        if (root->val != val) return false;

        return isSame(root->left, val) &&
               isSame(root->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true; // ✅ fix
        return isSame(root, root->val);
    }
};

int main() {
    // Example:
    //     1
    //    / \
    //   1   1

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    Solution obj;
    cout << (obj.isUnivalTree(root) ? "True" : "False") << endl;

    return 0;
}