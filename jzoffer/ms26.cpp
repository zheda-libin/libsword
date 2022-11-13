#include "base.h"


class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 本题最容易被忽略的点:
        //   第一个条件不满足, 也该接下来再check其他的.
        if (!A || !B) {
            return false;
        }

        bool flag = false;
        if (A->val == B->val) {
            flag = recur(A, B);
        }
        if (!flag) {
            flag = isSubStructure(A->left, B);
        }
        if (!flag) {
            flag = isSubStructure(A->right, B);
        }
        return flag;
    }

private:
    bool recur(TreeNode *A, TreeNode *B) {
        // 只要B是null, 不管A是什么结果都为true.(实际包含2种情况)
        if (!B) {
            return true;
        // 第二个条件B不为null, A为null, 必然为false
        } else if (!A) {
            return false;
        } else if (A->val == B->val){
            return recur(A->left, B->left) && recur(A->right, B->right);
        } else {
            return false;
        }

    }
};