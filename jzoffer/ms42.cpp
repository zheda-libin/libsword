#include "base.h"


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = 0, max_val=INT_MIN;
        for (auto num: nums) {
            if (tmp>0) {
                tmp += num;
            } else {
                tmp = num;
            }
            if (tmp>max_val) {
                max_val = tmp;
            }
        }
        return max_val;
    }
};
