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
    void traversal(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
            return;
        }

        traversal(root->left, v);
        traversal(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;

        traversal(root1, a);
        traversal(root2, b);

        return a == b;
    }
};

int main() {
    // Tree 1
    //     3
    //    / \
    //   5   1
    //  / \   \
    // 6   2   9

    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(5);
    t1->right = new TreeNode(1);
    t1->left->left = new TreeNode(6);
    t1->left->right = new TreeNode(2);
    t1->right->right = new TreeNode(9);

    // ✅ Updated Tree 2 (now leaf-similar)
    //     7
    //    / \
    //   6   2
    //      / \
    //     2   9

    TreeNode* t2 = new TreeNode(7);
    t2->left = new TreeNode(6);
    t2->right = new TreeNode(2);
    t2->right->left = new TreeNode(2);
    t2->right->right = new TreeNode(9);

    Solution obj;
    cout << (obj.leafSimilar(t1, t2) ? "True" : "False") << endl;

    return 0;
}