#include "s.h"
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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

    unordered_map<TreeNode*, pair<int,int>>  dp;


    void dfs(TreeNode* node){
        if(node==nullptr){
            return ;
        }

        dfs(node->left);
        dfs(node->right);

        int rob_this = dp[node->left].second + dp[node->right].second+node->val;
        int not_rob_this = max(dp[node->left].first, dp[node->left].second) + max(dp[node->right].first, dp[node->right].second);

        dp[node] = {rob_this, not_rob_this};

    }

    int rob(TreeNode* root) {

        dp[nullptr] = {0,0};

        dfs(root);

        return max(dp[root].first, dp[root].second);

    }
};
// @lc code=end

