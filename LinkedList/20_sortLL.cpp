//mergesort
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
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
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

        // Attach remaining
        curr->next = (l1) ? l1 : l2;

        return dummy.next;
    }

    // Merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list
        ListNode* mid = slow->next;
        slow->next = NULL;

        // Step 2: Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Step 3: Merge
        return merge(left, right);
    }
};

// Helpers
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver
int main() {
    ListNode* head = NULL;

    head = insert(head, 4);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);

    cout << "Original: ";
    printList(head);

    Solution sol;
    head = sol.sortList(head);

    cout << "Sorted: ";
    printList(head);

    return 0;
}