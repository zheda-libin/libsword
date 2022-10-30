struct ListNode {
    int val;
    ListNode *next;
};



class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && k > 0) {
            fast = fast->next;
            k--;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head || k<= 0) {
            return nullptr;
        }

        ListNode *pAhead = head;
        ListNode *pBehead = head;
        for(int i=0; i<k-1; ++i) {
            if (pAhead->next) {
                pAhead = pAhead->next;
            } else {
                return nullptr;
            }
        }
        while(pAhead->next) {
            pAhead = pAhead->next;
            pBehead = pBehead->next;
        }
        return pBehead;
    }
};
