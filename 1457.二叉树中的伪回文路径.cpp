#include "s.h"
/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
    vector<int> cur;
    int dfs(TreeNode *node ){
        int ret=0;
        cur[node->val]^=1;
        if(node->left==nullptr && node->right==nullptr){
            int ones=0;
            for(int i=1;i<=9;i++){
                if(cur[i]==1){
                    ones++;
                }
            }
            
            ret = (ones<=1)?1:0;
        }else{
            
            if(node->left)
                ret += dfs(node->left);
            if(node->right)
                ret += dfs(node->right);

            
        }
        cur[node->val]^=1;
        return ret;

    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        cur.resize(10);
        return dfs(root);
    }
};
// @lc code=end

