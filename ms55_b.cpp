#include "base.h"


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root)>=0;
    }
private:
    int height(TreeNode *root) {
        if (!root){
            return 0;
        }
        int left_h = height(root->left);
        int right_h = height(root->right);
        if (left_h==-1 || right_h==-1 || abs(left_h-right_h)>1) {
            return -1;
        }
        return max(left_h, right_h)+1;
    }
};
