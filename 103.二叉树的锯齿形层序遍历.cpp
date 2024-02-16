#include "s.h"
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<TreeNode*> q;

        if(!root){
            return {};
        }
        vector<vector<int>> ret;
        bool dir =1;
        q.push_back(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> t;
            vector<TreeNode*> next_level;
            for(int i=0;i<sz;i++){
                TreeNode *p = q.back();
                q.pop_back();
                t.push_back(p->val);
                if(dir){
                    if(p->left){
                        next_level.push_back(p->left);                       
                    }
                    if(p->right){
                        next_level.push_back(p->right);
                    }
                }else{
                    if(p->right){
                        next_level.push_back(p->right);
                    }
                    if(p->left){
                        next_level.push_back(p->left);
                    }
                }
                
            }
            // reverse(next_level.begin(), next_level.end());
            q = move(next_level);
            dir = !dir;
            ret.emplace_back(move(t));
        }
        return ret;
    }
};
// @lc code=end

