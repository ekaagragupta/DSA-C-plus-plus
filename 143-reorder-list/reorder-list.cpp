class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev_slow = NULL;

        vector<ListNode*> st;

        // Store all nodes
        ListNode* curr = head;
        while (curr != nullptr) {
            st.push_back(curr);
            curr = curr->next;
        }

        // Find middle
        while (fast != nullptr && fast->next != nullptr) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reorder using vector as stack
        curr = head;

        int n = st.size();

        for (int i = 0; i < n / 2; i++) {
            ListNode* last = st.back();
            st.pop_back();

            ListNode* next = curr->next;

            curr->next = last;
            last->next = next;

            curr = next;
        }

        curr->next = nullptr;

        return;
    }
};