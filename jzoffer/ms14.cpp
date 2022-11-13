#include "base.h"


class Solution {
public:
    int cuttingRope(int n) {
        if (n<2) {
            return 0;
        } else if (n==2) {
            return 1;
        } else if (n==3) {
            return 2;
        } else {
            vector<int> cache(n+1, 0);
            cache[0] = 0;
            cache[1] = 1;
            cache[2] = 2;
            cache[3] = 3;
            int max, product;
            for (int i=4; i<=n; ++i) {
                max = 0;
                for (int j=1; j<=i/2; ++j) {
                    product = cache[j] * cache[i-j];
                    if (product > max) {
                        max = product;
                    }
                }
                cache[i] = max;
            }
            return cache[n];
        }
    }
};