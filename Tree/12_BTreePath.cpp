#include <iostream>
#include <vector>
#include <string>
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
    void pathFinder(TreeNode* root, vector<string>& res, string currPath) {
        if (root == NULL) return;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            currPath += to_string(root->val);
            res.push_back(currPath);
            return;
        }

        // Add current node
        currPath += to_string(root->val) + "->";

        pathFinder(root->left, res, currPath);
        pathFinder(root->right, res, currPath);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        pathFinder(root, res, "");
        return res;
    }
};

int main() {
    // Example:
    //     1
    //    / \
    //   2   3
    //    \
    //     5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<string> paths = obj.binaryTreePaths(root);

    cout << "Paths:\n";
    for (string s : paths) {
        cout << s << endl;
    }

    return 0;
}