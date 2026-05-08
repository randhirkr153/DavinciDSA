// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         if (!node || !node->next) return;

//         ListNode* temp = node->next;
//         node->val = temp->val;
//         node->next = temp->next;

//         delete temp; // free memory (important in C++)
//     }
// };