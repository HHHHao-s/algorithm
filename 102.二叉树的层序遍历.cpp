#include "s.h"
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

    

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int> > ans;
        queue<TreeNode *> q;
        q.push(root);
        int count1=1;
        while(!q.empty()){
            int count2=0;
            vector<int> this_layer;
            for(int i=0;i<count1;i++){
                
                TreeNode *tmp = q.front();
                q.pop();
                this_layer.push_back(tmp->val);
                if(tmp->left!=nullptr){
                    q.push(tmp->left);
                    count2++;
                }
                if(tmp->right!=nullptr){
                    q.push(tmp->right);
                    count2++;
                }
            }            
            ans.push_back(this_layer);
            count1 = count2;
        }     
        return ans;
    }
};
// @lc code=end

