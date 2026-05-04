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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root == NULL) return res;

        q.push(root);

        while (!q.empty()) {

            int currsize = q.size();
            vector<int> currLevel;

            while (currsize > 0) {
                TreeNode* currnode = q.front();
                q.pop();

                currLevel.push_back(currnode->val);
                currsize--;

                if (currnode->left != NULL)
                    q.push(currnode->left);

                if (currnode->right != NULL)
                    q.push(currnode->right);
            }

            res.push_back(currLevel);
        }

        return res;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution obj;
    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}