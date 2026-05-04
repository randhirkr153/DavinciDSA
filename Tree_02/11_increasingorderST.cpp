#include <iostream>
#include <vector>
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
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);

        // create right-skewed tree
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* curr = dummy;

        for (int val : res) {
            curr->right = new TreeNode(val);
            curr = curr->right;
        }

        return dummy->right;
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

// Helper: Print right-skewed tree
void printRightSkewed(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
}

int main() {
    TreeNode* root = NULL;

    // Build BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 8);
    insert(root, 1);
    insert(root, 7);
    insert(root, 9);

    Solution sol;
    TreeNode* newRoot = sol.increasingBST(root);

    cout << "Increasing Order Search Tree: ";
    printRightSkewed(newRoot);

    return 0;
}