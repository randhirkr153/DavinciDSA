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
    TreeNode* createBST(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = createBST(nums, start, mid - 1);
        root->right = createBST(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }
};

// Inorder traversal (to verify)
void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}