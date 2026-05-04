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
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }

        if (val < node->val) {
            node->left = insertIntoBST(node->left, val);
        } else {
            node->right = insertIntoBST(node->right, val);
        }

        return node;
    }
};

// Inorder traversal (to check BST)
void inorder(TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;

    TreeNode* root = NULL;

    // Insert values
    root = sol.insertIntoBST(root, 5);
    sol.insertIntoBST(root, 3);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 4);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}