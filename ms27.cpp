#include "base.h"


class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        recur(root);
        return root;
    }
private:
    void recur(TreeNode *p) {
        if (!p) {
            return ;
        }
        TreeNode * tmp = p->left;
        p->left = p->right;
        p->right = tmp;
        if (p->left) {
            recur(p->left);
        }
        if (p->right) {
            recur(p->right);
        }
    }
};
