#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        flattenDFS(head);
        return head;
    }

private:
    // Returns tail of flattened list
    Node* flattenDFS(Node* head) {
        Node* curr = head;
        Node* last = NULL;

        while (curr) {
            Node* nextNode = curr->next;

            // If child exists
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                // Connect curr -> child
                curr->next = childHead;
                childHead->prev = curr;

                // Connect childTail -> nextNode
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                curr->child = NULL;
                last = childTail;
            } else {
                last = curr;
            }

            curr = nextNode;
        }

        return last;
    }
};

// Helper to print list
void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    /*
        Example:
        1 - 2 - 3
                |
                7 - 8
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    n3->child = n7;
    n7->next = n8;
    n8->prev = n7;

    Solution sol;
    Node* flat = sol.flatten(n1);

    cout << "Flattened List: ";
    printList(flat);

    return 0;
}