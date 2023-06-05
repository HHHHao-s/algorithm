#include "s.h"
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start

class Solution {
public:

    void myrightSideView(TreeNode *root, int depth){
        if(root==nullptr) return ;
        if(depth>ret.size()){
            ret.push_back(root->val);
        }
        myrightSideView(root->right, depth+1);
        myrightSideView(root->left, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};

        ret.push_back(root->val);
        myrightSideView(root->right, 2);
        myrightSideView(root->left, 2);
        
        return ret;
    }



private:
    vector<int> ret;
};
// @lc code=end

