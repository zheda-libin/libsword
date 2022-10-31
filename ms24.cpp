/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


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