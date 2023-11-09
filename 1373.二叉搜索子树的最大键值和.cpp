#include "s.h"
/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
private:
    int ans = 0;
    struct status{
        int sum,mi,mx;
    };

    status dfs(TreeNode *node){

        int x= node->val;
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        int ret=INT_MIN;
        if(left&&right){
            auto [l,lm,lx] = dfs(left);
            auto [r,rm,rx] = dfs(right);
            if(l!=INT_MIN && r!=INT_MIN && x>lx && x<rm){
                ans = max(ans, l+r+x);
                return {l+r+x,min({lm,rm,x}),max({lx,rx,x})};
            }else{
                return {INT_MIN,INT_MIN,INT_MAX};
            }
        }else if(left && right==nullptr){
            auto [l,lm,lx] = dfs(left);
            if(x>lx && l!=INT_MIN){
                ans = max(ans, l+x);
                return {l+x, min(lm,x),max(lx,x)};
            }else{
               return {INT_MIN,INT_MIN,INT_MAX};
            }
        }else if(right && left==nullptr){
            auto [r,rm,rx] = dfs(right);
            if(x<rm && r!=INT_MIN){
                ans = max(ans ,r+x);
                return {r+x, min(rm,x),max(x,rx)};
            }else{
                return {INT_MIN,INT_MIN,INT_MAX};
            }

        }else{
            // 叶子
            ans = max(ans, x);
            return {x,x,x};
        }
        return {INT_MIN,INT_MIN,INT_MAX};

    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

