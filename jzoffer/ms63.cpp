#include "base.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size()==1) {
            return 0;
        }
        int min_val = prices[0];
        // 此处有一点需要注意，如果是一个单调递减序列，那么应该不交易，最小是0.
        // int max_val = max(0, prices[1] - prices[0]);
        int max_val = prices[1] - prices[0];
        for(int i=2; i<prices.size(); ++i) {
            if (prices[i-1]<min_val) {
                min_val = prices[i-1];
            }
            if (prices[i]-min_val > max_val) {
                max_val = prices[i]-min_val;
            }
        }
        return max(0, max_val);
    }
};
