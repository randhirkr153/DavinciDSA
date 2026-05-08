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

// ---------------- ITERATIVE ----------------
class IterativeSolution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *temp;

        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

// ---------------- RECURSIVE ----------------
class RecursiveSolution {
public:
    ListNode* reverseHelper(ListNode* curr, ListNode* prev) {
        if (curr == NULL)
            return prev;

        ListNode* nextNode = curr->next;
        curr->next = prev;

        return reverseHelper(nextNode, curr);
    }

    ListNode* reverseList(ListNode* head) {
        return reverseHelper(head, NULL);
    }
};

// Helper to insert node
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
    ListNode* head = NULL;

    head = insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    IterativeSolution it;
    head = it.reverseList(head);

    cout << "Reversed (Iterative): ";
    printList(head);

    RecursiveSolution rec;
    head = rec.reverseList(head);

    cout << "Reversed Back (Recursive): ";
    printList(head);

    return 0;
}