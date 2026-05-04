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
    void findNodes(TreeNode* root, int x, int y,
                   int level[2], TreeNode* parent[2],
                   int currLevel, TreeNode* currParent) {

        if (root == NULL) return;

        if (root->val == x) {
            level[0] = currLevel;
            parent[0] = currParent;
        }

        if (root->val == y) {
            level[1] = currLevel;
            parent[1] = currParent;
        }

        findNodes(root->left, x, y, level, parent, currLevel + 1, root);
        findNodes(root->right, x, y, level, parent, currLevel + 1, root);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int level[2] = {-1, -1};
        TreeNode* parent[2] = {NULL, NULL};

        findNodes(root, x, y, level, parent, 0, NULL);

        return (level[0] == level[1]) && (parent[0] != parent[1]);
    }
};

int main() {
    // Example:
    //       1
    //      / \
    //     2   3
    //      \   \
    //       4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution obj;

    cout << (obj.isCousins(root, 4, 5) ? "True" : "False") << endl;

    return 0;
}