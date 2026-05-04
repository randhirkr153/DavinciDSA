#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> res;
        if (root == NULL) return res;

        map<int, int> mp; // hd -> node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            // overwrite every time (key difference from top view)
            mp[hd] = node->data;

            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};

int main() {

    /*
             1
           /   \
          2     3
           \   / \
            4 5   6
               \
                7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->right = new Node(7);

    Solution obj;
    vector<int> result = obj.bottomView(root);

    cout << "Bottom View: ";
    for (int x : result) cout << x << " ";

    return 0;
}