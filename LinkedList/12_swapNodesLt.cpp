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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* first = head;

        // Step 1: Move fast to kth node
        for (int i = 1; i < k; i++) {
            if (!fast) return head; // safety
            fast = fast->next;
        }

        first = fast; // kth node from start

        // Step 2: Move fast to end, slow to kth from end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Swap values
        int temp = first->val;
        first->val = slow->val;
        slow->val = temp;

        return head;
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

int main() {
    // Example: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    head = sol.swapNodes(head, k);

    printList(head);

    return 0;
}