#include <iostream>
using namespace std;

// Definition for binary tree node
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    // Tree 1
    //     1
    //    / \
    //   2   3

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);

    // Tree 2
    //     1
    //    / \
    //   2   3

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(t1, t2))
        cout << "Trees are SAME" << endl;
    else
        cout << "Trees are NOT SAME" << endl;

    return 0;
}