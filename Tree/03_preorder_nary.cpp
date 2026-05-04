#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        Preorder(root, ans);
        return ans;
    }

    void Preorder(Node* root, vector<int>& ans) {  // ✅ pass by reference
        if (root == NULL) return;

        ans.push_back(root->val);

        for (int i = 0; i < root->children.size(); i++) {
            Preorder(root->children[i], ans);
        }
    }
};

int main() {
    // Example:
    //        1
    //      / | \
    //     2  3  4
    //       / \
    //      5   6

    Node* root = new Node(1);
    Node* c1 = new Node(2);
    Node* c2 = new Node(3);
    Node* c3 = new Node(4);
    Node* c4 = new Node(5);
    Node* c5 = new Node(6);

    root->children = {c1, c2, c3};
    c2->children = {c4, c5};

    Solution obj;
    vector<int> res = obj.preorder(root);

    cout << "Preorder: ";
    for (int x : res) cout << x << " ";

    return 0;
}