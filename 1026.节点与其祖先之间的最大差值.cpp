#include "s.h"
/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int ans = 0;

    void get(TreeNode *node, int mx, int mn){

        if(node==nullptr){
            return;
        }
        ans = max({ans, abs(mx-node->val), abs(mn-node->val)});
        get(node->left, max(node->val, mx), min(node->val, mn));
        get(node->right,  max(node->val, mx), min(node->val, mn));
    }

    int maxAncestorDiff(TreeNode* root) {

        get(root, root->val, root->val);
        return ans;
    }
};
// @lc code=end

