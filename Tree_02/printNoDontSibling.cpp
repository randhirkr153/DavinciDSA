#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find nodes without siblings
void findNode(Node* root, vector<int>& res) {
    if (root == NULL) return;

    // if leaf node, ignore
    if (root->left == NULL && root->right == NULL) return;

    // both children present
    if (root->left != NULL && root->right != NULL) {
        findNode(root->left, res);
        findNode(root->right, res);
    }
    // only left child present
    else if (root->left != NULL) {
        res.push_back(root->left->data);
        findNode(root->left, res);
    }
    // only right child present
    else if (root->right != NULL) {
        res.push_back(root->right->data);
        findNode(root->right, res);
    }
}

// Main function to return result
vector<int> noSibling(Node* node) {
    vector<int> res;
    findNode(node, res);

    if (res.size() == 0)
        res.push_back(-1);

    sort(res.begin(), res.end());
    return res;
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
           \
            4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    vector<int> result = noSibling(root);

    cout << "Nodes without siblings: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}