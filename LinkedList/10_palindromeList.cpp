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
    // Find middle of linked list
    ListNode* midNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    // Compare two lists
    bool compare(ListNode* l1, ListNode* l2) {
        while (l1 != NULL && l2 != NULL) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

    // Main function
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // Step 1: Find middle
        ListNode* mid = midNode(head);

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(mid);

        // Step 3: Compare both halves
        bool result = compare(head, secondHalf);

        // Step 4 (optional): Restore list
        reverseList(secondHalf);

        return result;
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "Linked list is a palindrome." << endl;
    else
        cout << "Linked list is NOT a palindrome." << endl;

    return 0;
}