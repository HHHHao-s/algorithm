#include "s.h"
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int mydepth(TreeNode *root, int depth){
        if(root==NULL)return depth;
        int a = mydepth(root->left,depth+1);
        int b = mydepth(root->right,depth+1);
        return a>b?a:b;
    }

    int maxDepth(TreeNode* root) {
        return mydepth(root,0);
    }
};
// @lc code=end

