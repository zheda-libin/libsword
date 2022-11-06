#include "base.h"


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()){
            return nullptr;
        }

        m_preorder = preorder;
        for (int i=0; i<preorder.size(); ++i){
            // m_mapping.insert(make_pair<int, int>(inorder[i], i));
            m_mapping[inorder[i]] = i;
        }

        return makeTree(0, 0, preorder.size()-1);
    }
private:
    vector<int> m_preorder;
    unordered_map<int, int> m_mapping;
    // root指前序遍历中当前子树根节点的index;
    // left和right指中序遍历中左右边界范围.
    TreeNode* makeTree(int root, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        TreeNode* p = new TreeNode(m_preorder[root]);
        int idx = m_mapping[m_preorder[root]];
        p->left = makeTree(root+1, left, idx-1);
        p->right = makeTree(root+1+(idx-1)-left+1, idx+1, right);
        return p;
    }
};
