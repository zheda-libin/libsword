#include "base.h"


class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        } else if (grid[0].empty()) {
            return 0;
        }

        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        vector<int> cache(cols, 0);

        for (int i=0; i<rows;++i) {
            for (int j=0; j<cols;++j) {
                int upper = i>0? cache[j]: 0;
                int left = j>0? cache[j-1]: 0;
                cache[j] = max(upper, left) + grid[i][j];
            }
        }
        return cache.back();
    }
};
