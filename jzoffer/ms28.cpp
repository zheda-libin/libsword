#include "base.h"


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return recur(root, root);
    }
private:
    bool recur(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return recur(left->left, right->right) && recur(left->right, right->left);
    }
};
