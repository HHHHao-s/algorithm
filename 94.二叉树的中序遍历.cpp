#include "s.h"
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

class Solution {
public:

    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};
// @lc code=end

