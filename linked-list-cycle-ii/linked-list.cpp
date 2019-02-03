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
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head || NULL == head->next) {
            return NULL;
        }
        if (head == head->next) {
            return head;
        }

        ListNode dummyNode(0);
        dummyNode.next = head;

        ListNode *oneStep = head, *twoStep = head->next;
        while (oneStep != twoStep) {
            if (NULL == twoStep || NULL == twoStep->next) {
                return NULL;
            }
            if (head == twoStep || head == twoStep->next) {
                return head;
            }

            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }

        for (auto tmp = &dummyNode; tmp != oneStep; oneStep = oneStep->next, tmp = tmp->next) {}

        return oneStep;
    }
};