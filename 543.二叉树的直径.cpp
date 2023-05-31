#include "s.h"
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int max=0;

    int mydiameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int a = mydiameterOfBinaryTree(root->left);
        int b = mydiameterOfBinaryTree(root->right);
        max = max>a+b?max:a+b;
        return a>b?a+1:b+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int a = mydiameterOfBinaryTree(root->left);
        int b = mydiameterOfBinaryTree(root->right);
        max = max>a+b?max:a+b;
        return max;
    }
};
// @lc code=end

