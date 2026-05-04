#include <iostream>
#include <vector>
using namespace std;

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
    void inorder(Node *root, vector<Node*> &res) {
        if (root == NULL) return;

        inorder(root->left, res);
        res.push_back(root);
        inorder(root->right, res);
    }

    Node* inOrderSuccessor(Node* root, Node* x) {
        vector<Node*> res;
        inorder(root, res);

        for (int i = 0; i < res.size(); i++) {
            if (res[i] == x && i < res.size() - 1) {
                return res[i + 1];
            }
        }
        return NULL;
    }
};

// Insert helper
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int main() {
    Node* root = NULL;

    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    Solution sol;

    Node* x = root->left->right; // node 12
    Node* ans = sol.inOrderSuccessor(root, x);

    if (ans)
        cout << "Successor: " << ans->data << endl;
    else
        cout << "No Successor" << endl;

    return 0;
}