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
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) return true;
        if (l == NULL || r == NULL) return false;
        if (l->val != r->val) return false;

        return isMirror(l->left, r->right) &&
               isMirror(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};

int main() {
    // Example symmetric tree:
    //        1
    //      /   \
    //     2     2
    //    / \   / \
    //   3   4 4   3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is SYMMETRIC" << endl;
    else
        cout << "Tree is NOT SYMMETRIC" << endl;

    return 0;
}