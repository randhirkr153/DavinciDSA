#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node(int _val) {
        val = _val;
    }
};

class Solution {
public:
    void inorder(Node* root) {
        if (root == NULL) return;

        int n = root->children.size();

        // Traverse all children except last
        for (int i = 0; i < n - 1; i++) {
            inorder(root->children[i]);
        }

        // Visit root
        cout << root->val << " ";

        // Traverse last child
        if (n > 0) {
            inorder(root->children[n - 1]);
        }
    }
};

int main() {
    // Example:
    //        1
    //      / | \
    //     2  3  4

    Node* root = new Node(1);
    Node* c1 = new Node(2);
    Node* c2 = new Node(3);
    Node* c3 = new Node(4);

    root->children = {c1, c2, c3};

    Solution obj;
    obj.inorder(root);

    return 0;
}