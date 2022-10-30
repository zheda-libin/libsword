struct ListNode {
    int val;
    ListNode *next;
};


class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // 和原来的那道题不一样了, 就是一个简单的
        if (!head){
            return nullptr;
        }

        ListNode* pNode = head;
        if (head->val == val) {    
            // free(pNode);
            return head->next;
        } 

        while(pNode->next && pNode->next->val != val) {
            pNode = pNode->next;
        }
        if (pNode->next && pNode->next->val == val) {
            pNode->next = pNode->next->next;
            return head;
        }
        return nullptr;
    }
};