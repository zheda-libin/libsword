#include "base.h"

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int target) {
        if (!root) {
            return ;
        }

        // 更新过程
        path.emplace_back(root->val);
        target -= root->val;

        // 判断 + 递归.
        if (!root->left && !root->right && !target) {
            ret.emplace_back(path);
        }

        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ret;
    }
};
