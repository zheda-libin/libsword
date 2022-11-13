#include "base.h"


// 解法1.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>>();
        vector<vector<int>> result;
        deque<TreeNode *> queue;
        TreeNode *tmp;

        queue.push_back(root);
        int current=1, next=0;
        while(!queue.empty()) {
            tmp = queue.front();
            queue.pop_front();
            m_val.push_back(tmp->val);
            current--;

            if (tmp->left) {
                queue.push_back(tmp->left);
                next++;
            }
            if (tmp->right) {
                queue.push_back(tmp->right);
                next++;
            }

            if (current<=0) {
                result.push_back(m_val);
                m_val.clear();
                current=next;
                next=0;
            }
        }
        return result;
    }
private:
    vector<int> m_val;
};


// 解法2.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)  return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int length = q.size();
            for(int i=0; i<length; i++){
                temp.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
};
