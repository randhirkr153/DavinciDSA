#include <iostream>
using namespace std;



// implementing Floyd’s Cycle Detection (Tortoise & Hare), which is correct in concept 👍 — but there’s a small mistake in your loop condition.
// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to detect cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    Solution obj;

    if (obj.hasCycle(head))
        cout << "Cycle detected in the linked list." << endl;
    else
        cout << "No cycle in the linked list." << endl;

    return 0;
}