#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, int& preIdx, int boundary) {
        if (preIdx == preorder.size() || preorder[preIdx] > boundary)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        root->left = buildTree(preorder, preIdx, root->val);
        root->right = buildTree(preorder, preIdx, boundary);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIdx = 0;
        return buildTree(preorder, preIdx, INT_MAX);
    }
};

// Inorder traversal (to verify BST)
void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}