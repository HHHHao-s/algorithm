#include "s.h"
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int mykthSmallest(TreeNode * root){
        if(root==nullptr) return -1;
        int a;
        if((a = mykthSmallest(root->left))!=-1){
            return a;
        }
        need_--;
        if(need_==0) return root->val;
        if((a = mykthSmallest(root->right))!=-1){
            return a;
        }
        return -1;

    }

    int kthSmallest(TreeNode* root, int k) {
        need_ = k;

        return mykthSmallest(root);
    }
private:
    int need_;

};
// @lc code=end

