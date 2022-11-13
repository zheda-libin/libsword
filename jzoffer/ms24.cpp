#include "base.h"


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *prev=nullptr, *cur=head, *next;
        while(cur) {
            next = cur->next;
            
            // update.
            cur->next = prev;   // 改变数组指向.
            prev = cur;
            cur = next;
        }

        return prev;
    }
};