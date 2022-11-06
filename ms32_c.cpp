#include "base.h"


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();
        TreeNode *tmp;
        deque<TreeNode*> queue;
        vector<vector<int>> result;
        int current = 1, next = 0;
        bool is_reverse = false;

        queue.push_back(root);
        while(!queue.empty()) {
            tmp = queue.front();
            queue.pop_front();
            current--;
            m_val.push_back(tmp->val);

            if (tmp->left) {
                queue.push_back(tmp->left);
                next++;
            }
            if (tmp->right) {
                queue.push_back(tmp->right);
                next++;
            }

            if (current<=0) {
                if (is_reverse) {
                    reverse(m_val.begin(), m_val.end());
                }

                result.push_back(m_val);
                m_val.clear();
                is_reverse = !is_reverse;
                current = next;
                next = 0;
            }
        }
        return result;
    }
private:
    vector<int> m_val;
};
