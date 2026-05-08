#include <iostream>
using namespace std;

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

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find starting node
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // start of cycle
            }
        }
        return NULL;
    }
};

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if (result != NULL)
        cout << "Cycle starts at node with value: " << result->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}