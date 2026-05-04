#include <iostream>
using namespace std;

// Define TreeNode
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
    TreeNode* merge(TreeNode* root1, TreeNode* root2) {

        if (root1 == NULL && root2 == NULL) return NULL;
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;

        // Create new node
        TreeNode* newNode = new TreeNode(root1->val + root2->val);

        newNode->left = merge(root1->left, root2->left);
        newNode->right = merge(root1->right, root2->right);

        return newNode;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};

// Inorder print to verify result
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Tree 1
    //     1
    //    / \
    //   3   2
    //  /
    // 5

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    // Tree 2
    //     2
    //    / \
    //   1   3
    //    \   \
    //     4   7

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    Solution obj;
    TreeNode* merged = obj.mergeTrees(t1, t2);

    cout << "Inorder of merged tree: ";
    inorder(merged);

    return 0;
}