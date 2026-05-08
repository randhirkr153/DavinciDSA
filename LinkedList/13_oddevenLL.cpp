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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

// Helper function to insert node at end
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    ListNode* head = NULL;

    // Example input: 1 2 3 4 5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.oddEvenList(head);

    cout << "After Odd-Even Rearrangement: ";
    printList(head);

    return 0;
}