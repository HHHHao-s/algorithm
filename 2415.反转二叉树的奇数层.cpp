#include "s.h"
/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
    TreeNode* reverseOddLevels(TreeNode* root) {


        queue<TreeNode* > q;
        stack<int> num;
        q.push(root);
        bool odd=false;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode *node = q.front();
                q.pop();
                if(odd){
                    node->val=num.top();
                    num.pop();
                }else{
                    if(node->left ){
                        num.push(node->left->val);
                        num.push(node->right->val);
                    }

                }
                if(node->left){
                    q.push(node->left);
                    q.push(node->right);
                }

            }
            odd = !odd;
        }
        return root;
    }
};
// @lc code=end

