/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) {
            return NULL;
        }

        for (auto cur = head; cur; cur = cur->next->next) {
            auto tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
        }

        for (auto cur = head; NULL != cur; cur = cur->next->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
        }

        RandomListNode dummyNode(0);
        for (auto cur = head, copied = &dummyNode; cur; cur = cur->next, copied = copied->next) {
            copied->next = cur->next;
            cur->next = cur->next->next;
        }

        return dummyNode.next;
    }
};