#include <bits/stdc++.h>
using namespace std;

// Definition of N-ary Tree Node
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;

        if (root == NULL) return res;

        q.push(root);

        while (!q.empty()) {

            int currsize = q.size();
            vector<int> currLevel;

            while (currsize > 0) {
                Node* currnode = q.front();
                q.pop();

                currLevel.push_back(currnode->val);
                currsize--;

                // push all children
                for (auto child : currnode->children) {
                    if (child != NULL)
                        q.push(child);
                }
            }

            res.push_back(currLevel);
        }

        return res;
    }
};

int main() {

    /*
            1
         /  |  \
        2   3   4
           / \
          5   6
    */

    Node* root = new Node(1);

    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    root->children = {node2, node3, node4};
    node3->children = {node5, node6};

    Solution obj;
    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}