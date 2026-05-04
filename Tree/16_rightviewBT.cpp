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
    void dfs(TreeNode* root, vector<int>& res, int level) {
        if (root == NULL) return;

        // First node at this level
        if (level == res.size()) {
            res.push_back(root->val);
        }

        // Right first (important!)
        dfs(root->right, res, level + 1);
        dfs(root->left, res, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};

int main() {
    // Example:
    //       1
    //      / \
    //     2   3
    //      \   \
    //       5   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> ans = obj.rightSideView(root);

    cout << "Right View: ";
    for (int x : ans) cout << x << " ";

    return 0;
}

// BFS APPROACH
// vector<int> rightSideView(TreeNode* root) {
//     vector<int> res;
//     if (!root) return res;

//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         int size = q.size();

//         for (int i = 0; i < size; i++) {
//             TreeNode* node = q.front(); q.pop();

//             if (i == size - 1)  // last node in level
//                 res.push_back(node->val);

//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//     }

//     return res;
// }