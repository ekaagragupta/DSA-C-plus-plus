class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr; // Fix 1: Starts as nullptr because the new tail must point to nullptr

        while (curr != nullptr) {
            ListNode* next = curr->next; // Store the next node before breaking the link
            curr->next = prev;          // Reverse the current node's pointer

            prev = curr;                // Move prev one step forward
            curr = next;                // Move curr one step forward
        }

        return prev; // Fix 2: prev is now pointing to the new head (5)
    }
};