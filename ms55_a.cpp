#include "base.h"


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
