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
    void inorder(TreeNode* root, vector<int> &res) {
        if (root == NULL) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root, res);

        int front = 0;
        int rear = res.size() - 1;

        while (front < rear) {
            int sum = res[front] + res[rear];

            if (sum == k) return true;
            else if (sum > k) rear--;
            else front++;
        }

        return false;
    }
};

// Helper: Insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int main() {
    TreeNode* root = NULL;

    // Build BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);

    Solution sol;

    int k = 9;

    if (sol.findTarget(root, k))
        cout << "Pair exists with sum " << k << endl;
    else
        cout << "No pair found with sum " << k << endl;

    return 0;
}