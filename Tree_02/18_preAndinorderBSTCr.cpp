#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode* constructTree(vector<int>& preorder,
                            unordered_map<int, int>& mp,
                            int start, int end, int& preIdx) {

        if (start > end) return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int currIdx = mp[preorder[preIdx]];
        preIdx++;

        root->left = constructTree(preorder, mp, start, currIdx - 1, preIdx);
        root->right = constructTree(preorder, mp, currIdx + 1, end, preIdx);

        return root;
    }

    unordered_map<int, int> populate(vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return mp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp = populate(inorder);
        int preIdx = 0;
        return constructTree(preorder, mp, 0, inorder.size() - 1, preIdx);
    }
};

// Inorder traversal (to verify)
void inorderPrint(TreeNode* root) {
    if (!root) return;

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

// Preorder traversal (to verify)
void preorderPrint(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderPrint(root);
    cout << endl;

    return 0;
}