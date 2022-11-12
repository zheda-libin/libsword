#include "base.h"


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        int lengthA = getListNodeLength(headA);
        int lengthB = getListNodeLength(headB);

        ListNode *long_list;
        ListNode *short_list;
        int diff;
        if (lengthA > lengthB){
            long_list = headA;
            short_list = headB;
            diff = lengthA - lengthB;
        } else {
            long_list = headB;
            short_list = headA;
            diff = lengthB - lengthA;
        }

        for(int i=0; i<diff; ++i) {
            long_list = long_list->next;
        }
        while(long_list && short_list && long_list!=short_list){
            long_list = long_list->next;
            short_list = short_list->next;
        }
        return long_list;
    }

private:
    int getListNodeLength(ListNode *p) {
        int length = 0;
        while (p) {
            length++;
            p = p->next;
        }
        return length;
    }
};