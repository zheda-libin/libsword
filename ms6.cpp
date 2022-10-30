#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};


// 用递归非常地慢, 并且也非常地消耗内存.
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        // 实际上是递归终止条件, 我们并不真的关心它return了什么.
        if (!head) {
            return res;
        }
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
