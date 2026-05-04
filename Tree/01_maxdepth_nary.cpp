#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define Node
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
    int maxDepth(Node* root) {
        if (root == NULL) return 0;

        int ans = 0;

        for (int i = 0; i < root->children.size(); i++) {
            int temp = maxDepth(root->children[i]);
            ans = max(ans, temp);
        }

        return 1 + ans;
    }
};

int main() {
    // Example N-ary Tree:
    //        1
    //      / | \
    //     2  3  4
    //       / \
    //      5   6

    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* child4 = new Node(5);
    Node* child5 = new Node(6);

    root->children = {child1, child2, child3};
    child2->children = {child4, child5};

    Solution obj;
    cout << "Max Depth: " << obj.maxDepth(root) << endl;

    return 0;
}