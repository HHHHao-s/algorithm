#include "s.h"
/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    unordered_map<TreeNode*, array<array<int,2>,2>> memo;

    int dfs(TreeNode* node, int watched, int need){
        
        if(memo[node][watched][need]!=0){
            return memo[node][watched][need];
        }

        if(!watched && need ){
            // 01
            if(node==nullptr){
                return 10000;
            }
            int a = dfs(node->left, 1, 0)+dfs(node->right,1,0)+1;
            memo[node][watched][need] = a;
            return a;
        }else if( !watched &&!need ){
            // 00
            if(node==nullptr){
               return 0;
            }
            int a = dfs(node->left, 1, 0)+dfs(node->right,1,0)+1;
            int b = dfs(node->left, 0, 1)+dfs(node->right,0,0);
            int c = dfs(node->left, 0, 0)+dfs(node->right,0,1);
            memo[node][watched][need] = min({a,b,c});
            return min({a,b,c});
        }else if(watched && !need){
            // 10
            if(node==nullptr){
               return 0;
            }
            int a = dfs(node->left, 0, 0)+dfs(node->right,0,0);
            int b = dfs(node->left, 1, 0)+dfs(node->right,1,0)+1;
            memo[node][watched][need] = min(a,b);
            return min(a,b);
        }
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {

        return dfs(root, 0, 0);

    }
};
// @lc code=end

