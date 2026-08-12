/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node;
        ListNode* curr = head;
        while (curr != nullptr) {
            node.push_back(curr);
            curr = curr->next;
        }
        if (n == node.size()) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        // Find previous and node to delete
        ListNode* prev = node[node.size() - n - 1];
        ListNode* delnode = node[node.size() - n];

        prev->next = delnode->next;
        delete delnode;
        return head;
    }
};
