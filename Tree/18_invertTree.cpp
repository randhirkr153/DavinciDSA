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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;

        // Swap subtrees
        TreeNode* leftSub = invertTree(root->right);
        TreeNode* rightSub = invertTree(root->left);

        root->left = leftSub;
        root->right = rightSub;

        return root;
    }
};

// Inorder traversal to check result
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Original Tree:
    //     4
    //    / \
    //   2   7
    //  / \ / \
    // 1  3 6  9

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;

    cout << "Inorder BEFORE invert: ";
    inorder(root);
    cout << endl;

    obj.invertTree(root);

    cout << "Inorder AFTER invert: ";
    inorder(root);
    cout << endl;

    return 0;
}