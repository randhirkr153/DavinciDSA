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

    // Step 1: Create parent mapping
    void populateMap(TreeNode* curr, TreeNode* parent,
                     unordered_map<TreeNode*, TreeNode*>& parentMap)
    {
        if (curr == NULL) return;

        parentMap[curr] = parent;

        populateMap(curr->left, curr, parentMap);
        populateMap(curr->right, curr, parentMap);
    }

    // Step 2: DFS to find nodes at distance K
    void findNodes(TreeNode* curr, int k,
                   set<TreeNode*>& visited,
                   unordered_map<TreeNode*, TreeNode*>& parentMap,
                   vector<int>& ans)
    {
        if (curr == NULL || visited.count(curr)) return;

        visited.insert(curr);

        if (k == 0) {
            ans.push_back(curr->val);
            return;
        }

        // left
        findNodes(curr->left, k - 1, visited, parentMap, ans);

        // right
        findNodes(curr->right, k - 1, visited, parentMap, ans);

        // parent
        if (parentMap[curr] != NULL) {
            findNodes(parentMap[curr], k - 1, visited, parentMap, ans);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parentMap;
        populateMap(root, NULL, parentMap);

        vector<int> ans;
        set<TreeNode*> visited;

        findNodes(target, k, visited, parentMap, ans);

        return ans;
    }
};

int main() {

    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // node with value 5
    int k = 2;

    Solution obj;
    vector<int> result = obj.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}