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
    ListNode * reverseList(ListNode *head, ListNode *appendage = nullptr) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        auto doneHead = appendage;
        for (auto todoHead = head; nullptr != todoHead; ) {
            auto tmp = todoHead->next;
            todoHead->next = doneHead;
            doneHead = todoHead;
            todoHead = tmp;
        }

        return doneHead;
    }

    ListNode * getMiddle(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *oneStep = head, *twoStep = head->next;
        for ( ; nullptr != twoStep && nullptr != twoStep->next; oneStep = oneStep->next, twoStep = twoStep->next->next) {}

        return oneStep;
    }

    void reorderList(ListNode* head) {
        if (nullptr == head || nullptr == head->next) {
            return;
        }

        ListNode *middle = getMiddle(head);
        ListNode *l1 = head, *l2 = reverseList(middle->next);
        middle->next = nullptr;

        ListNode dummyNode(0);
        ListNode *tail = &dummyNode;

        while (nullptr != l2) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;

            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
        if (nullptr != l1) {
            tail->next = l1;
        }
    }
};