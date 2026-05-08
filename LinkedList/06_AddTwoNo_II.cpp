#include <iostream>
using namespace std;

// Definition
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
    // Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Step 1: Reverse both lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode dummy(-1);
        ListNode* curr = &dummy;

        int carry = 0;

        // Step 2: Add numbers
        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Step 3: Reverse result
        return reverseList(dummy.next);
    }
};

// Helpers
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
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

int main() {
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    // 7243
    l1 = insert(l1, 7);
    insert(l1, 2);
    insert(l1, 4);
    insert(l1, 3);

    // 564
    l2 = insert(l2, 5);
    insert(l2, 6);
    insert(l2, 4);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}