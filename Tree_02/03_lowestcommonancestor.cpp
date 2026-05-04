#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) return NULL;

        // if either p or q is found
        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode* leftSubTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSubTree = lowestCommonAncestor(root->right, p, q);

        // if both sides return non-null → this is LCA
        if (leftSubTree != NULL && rightSubTree != NULL)
            return root;

        // if only left side has result
        if (leftSubTree != NULL)
            return leftSubTree;

        // if only right side has result
        if (rightSubTree != NULL)
            return rightSubTree;

        return NULL;
    }
};

int main() {

    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;              // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    Solution obj;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        cout << "LCA: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}