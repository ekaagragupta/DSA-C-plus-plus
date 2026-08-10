class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* pa = headA;
        ListNode* pb = headB;

        while (pa != pb) {

            if (pa == nullptr)
                pa = headB;
            else
                pa = pa->next;

            if (pb == nullptr)
                pb = headA;
            else
                pb = pb->next;
        }

        return pa;
    }
};