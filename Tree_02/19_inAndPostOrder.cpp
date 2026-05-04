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
    TreeNode* constructTree(vector<int>& postorder,
                            unordered_map<int, int>& mp,
                            int start, int end, int& postIdx) {

        if (start > end) return NULL;

        TreeNode* root = new TreeNode(postorder[postIdx]);

        int currIdx = mp[postorder[postIdx]];
        postIdx--;

        // IMPORTANT: build RIGHT first
        root->right = constructTree(postorder, mp, currIdx + 1, end, postIdx);
        root->left  = constructTree(postorder, mp, start, currIdx - 1, postIdx);

        return root;
    }

    unordered_map<int, int> populate(vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return mp;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp = populate(inorder);
        int postIdx = postorder.size() - 1;
        return constructTree(postorder, mp, 0, inorder.size() - 1, postIdx);
    }
};

// Inorder print
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

// Postorder print
void postorderPrint(TreeNode* root) {
    if (!root) return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderPrint(root);
    cout << endl;

    return 0;
}