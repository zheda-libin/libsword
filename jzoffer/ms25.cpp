#include "base.h"


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2){
            return l1;
        } else if (l1->val < l2->val) {
            l1->next= mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev = new ListNode(-1), *preHead=prev;

        while(l1 && l2) {
            // 完成一次三方计算
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            // prev自增1
            prev = prev->next;
        }

        if (l1) {
            prev->next = l1;
        } else {
            prev->next = l2;
        }

        prev=preHead->next;
        delete preHead;

        return prev;
    }
};
