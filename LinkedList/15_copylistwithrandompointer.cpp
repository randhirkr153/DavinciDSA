#include <iostream>
#include <unordered_map>
using namespace std;

// Definition
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        // Step 1: Create all nodes
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        // Step 2: Assign next & random pointers
        while (curr) {
            mp[curr]->next = mp[curr->next];       // safe: NULL handled
            mp[curr]->random = mp[curr->random];   // safe: NULL handled
            curr = curr->next;
        }

        return mp[head];
    }
};

// Helper to print list
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val;
        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}

// Main
int main() {
    // Creating example:
    // 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    n1->random = n3; // 1 -> 3
    n2->random = n1; // 2 -> 1
    n3->random = n2; // 3 -> 2

    Solution sol;
    Node* copy = sol.copyRandomList(n1);

    cout << "Copied List:\n";
    printList(copy);

    return 0;
}