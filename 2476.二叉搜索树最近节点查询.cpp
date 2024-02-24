#include "s.h"
/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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
    void build(vector<int>&arr, TreeNode*node){
        if(!node){
            return ;
        }
        build(arr, node->left);
        arr.push_back(node->val);
        build(arr, node->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        vector<int> arr;
        build(arr, root);
        vector<vector<int>> ans;
        for(auto query: queries){
            auto it = lower_bound(arr.begin(), arr.end(), query);
            vector<int> q(2, -1);
            if(it!=arr.end()){
                q[1] = *it;
                if(*it==query){
                    q[0] = *it;
                }else{
                    if(it!=arr.begin()){
                        --it;
                        q[0] = *it;
                    }
                }
            }else{
                q[0] = *(--it);
            }
            ans.emplace_back(move(q));
        }       
        return ans;
    }
};
// @lc code=end

