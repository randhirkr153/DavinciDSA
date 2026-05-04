#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};

int main() {
    // Example tree:
    //     1
    //    / \
    //   2   3

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;
    vector<int> result = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}