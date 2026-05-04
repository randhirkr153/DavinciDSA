#include <iostream>
#include <vector>
using namespace std;

// Definition for N-ary tree node
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }

    void postorderHelper(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        for (int i = 0; i < root->children.size(); i++) {
            postorderHelper(root->children[i], ans);
        }

        ans.push_back(root->val);
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
    vector<int> res = obj.postorder(root);

    cout << "Postorder: ";
    for (int x : res) cout << x << " ";

    return 0;
}