#include "s.h"
/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> ans;

        function<void(TreeNode*, int, int)> dfs =[&](TreeNode *node, int col, int row){

            if(node==nullptr){
                return ;
            }
            ans[col][row].insert(node->val);
            dfs(node->left, col-1, row+1);
            dfs(node->right , col+1, row+1);
            
            

        };
        dfs(root ,0, 0);
        vector<vector<int>> ret;
        for(auto [col, a]: ans){
            vector<int> t;
            for(auto [row, b] : a){
                for(auto c: b){
                    t.push_back(c);
                }
            }
            ret.emplace_back(move(t));
        }

        return ret;

    }
};
// @lc code=end

