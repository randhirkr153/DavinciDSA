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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
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
    vector<int> result = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}