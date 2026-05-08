#include <iostream>
using namespace std;

// Definition of ListNode
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Attach remaining nodes
        if (l1) curr->next = l1;
        if (l2) curr->next = l2;

        return dummy.next;
    }
};

// Helper: Insert node at end
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

// Helper: Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    // First sorted list
    l1 = insert(l1, 1);
    insert(l1, 3);
    insert(l1, 5);

    // Second sorted list
    l2 = insert(l2, 2);
    insert(l2, 4);
    insert(l2, 6);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}