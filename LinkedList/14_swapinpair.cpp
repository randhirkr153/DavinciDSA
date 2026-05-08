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
    // Recursive function
    ListNode* swapAdjacentNodes(ListNode* head) {
        // Base case
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        // Recursively swap rest
        first->next = swapAdjacentNodes(second->next);

        // Swap current pair
        second->next = first;

        return second; // new head of this pair
    }

    ListNode* swapPairs(ListNode* head) {
        return swapAdjacentNodes(head);
    }
};

// Insert helper
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

// Print helper
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main
int main() {
    ListNode* head = NULL;

    // Example: 1 -> 2 -> 3 -> 4
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    cout << "Original: ";
    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    cout << "After Swap Pairs: ";
    printList(head);

    return 0;
}