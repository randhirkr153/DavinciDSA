#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   // last node before duplicate sequence
        ListNode* curr = head;

        while (curr != NULL) {
            // Detect duplicates
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;

                // Skip ALL nodes with this value
                while (curr != NULL && curr->val == dupVal) {
                    curr = curr->next;
                }

                prev->next = curr; // remove duplicates
            } 
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Example: 1->2->3->3->4->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.deleteDuplicates(head);

    printList(head);

    return 0;
}