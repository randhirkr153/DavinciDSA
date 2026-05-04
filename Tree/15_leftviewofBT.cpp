#include <iostream>
#include <vector>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void viewGenerator(Node* root, vector<int>& res, int level) {
        if (root == NULL) return;

        // First node at this level
        if (level == res.size()) {
            res.push_back(root->data);
        }

        // Left first (important!)
        viewGenerator(root->left, res, level + 1);
        viewGenerator(root->right, res, level + 1);
    }

    vector<int> leftView(Node* root) {
        vector<int> res;
        viewGenerator(root, res, 0);
        return res;
    }
};

int main() {
    // Example:
    //       1
    //      / \
    //     2   3
    //      \   \
    //       4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    Solution obj;
    vector<int> ans = obj.leftView(root);

    cout << "Left View: ";
    for (int x : ans) cout << x << " ";

    return 0;
}