#include <iostream>
#include <algorithm>  // for max
using namespace std;

// Define structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;

        int leftH = 1 + maxDepth(root->left);
        int rightH = 1 + maxDepth(root->right);

        return max(leftH, rightH);
    }
};

int main() {
    // Creating a sample tree
    //       1
    //      / \
    //     2   3
    //    /
    //   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution obj;
    cout << "Max Depth: " << obj.maxDepth(root) << endl;

    return 0;
}