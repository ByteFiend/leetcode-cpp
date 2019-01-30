/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head || n <= 0) {
            return head;
        }

        ListNode *tail = head;
        for (auto i = 0; i < n; ++i) {
            if (NULL == tail) {
                return head;
            }
            tail = tail->next;
        }

        ListNode dummyNode(0);
        dummyNode.next = head;

        ListNode *prev = &dummyNode;
        while (NULL != tail) {
            tail = tail->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return dummyNode.next;
    }
};