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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode* curr = head;
        int count = 0;

        // Step 1: Check if k nodes exist
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        // Step 2: If we have k nodes → reverse
        if (count == k) {
            curr = reverseKGroup(curr, k); // recursive call

            while (count--) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }

        return head;
    }
};

// Helper: Insert
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

// Helper: Print
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Main
int main() {
    ListNode* head = NULL;

    // 1 → 2 → 3 → 4 → 5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    int k = 2;

    Solution sol;
    head = sol.reverseKGroup(head, k);

    printList(head);

    return 0;
}