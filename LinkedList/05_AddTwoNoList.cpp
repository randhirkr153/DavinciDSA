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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int firstVal = (l1) ? l1->val : 0;
            int secondVal = (l2) ? l2->val : 0;

            int sum = firstVal + secondVal + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};

// Helper: Insert node
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);

    return head;
}

// Print list
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

    // Number: 342
    l1 = insert(l1, 2);
    insert(l1, 4);
    insert(l1, 3);

    // Number: 465
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