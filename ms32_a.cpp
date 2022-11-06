#include "base.h"


class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root)
            return vector<int>();
        deque<TreeNode *> queue;
        vector<int> result;

        TreeNode *p = root, *tmp;
        queue.push_back(p);
        while(!queue.empty()) {
            // 先出栈, 处理
            tmp = queue.front();
            queue.pop_front();
            result.push_back(tmp->val);
            // 然后再看出栈元素的左右子树
            if (tmp->left)
                queue.push_back(tmp->left);
            if (tmp->right)
                queue.push_back(tmp->right);
        }
        return result;
    }
};
