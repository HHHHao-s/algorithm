#include "s.h"
/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    vector<int> back_sum;

    void dfs(TreeNode *node){
        if(node==nullptr){
            return;
        }
        back_sum[node->val]=node->val;
        dfs(node->left);
        dfs(node->right);
    }

    void dfs2(TreeNode *node){
        if(node==nullptr){
            return;
        }
        node->val=back_sum[node->val];
        dfs2(node->left);
        dfs2(node->right);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        back_sum.resize(101);
        dfs(root);
        int cur = 0;
        for(int i=101;i-->0;){
            
            cur+=back_sum[i];
            back_sum[i]=cur;
            cout << cur << endl;

        }
        dfs2(root);
        return root;
    }
};
// @lc code=end

