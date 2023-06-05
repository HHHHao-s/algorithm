#include "s.h"
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution
{
public:
    TreeNode *pre{nullptr};

    void myflatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        TreeNode *tmp1 = root->left;
        TreeNode *tmp2 = root->right;
        root->left = nullptr;
        root->right = nullptr;
        pre->right = root;
        pre = pre->right;
        myflatten(tmp1);
        myflatten(tmp2);
    }

    TreeNode *flatten(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        pre = root;
        TreeNode *tmp1 = root->left;
        TreeNode *tmp2 = root->right;
        root->left = nullptr;
        root->right = nullptr;
        myflatten(tmp1);
        myflatten(tmp2);

        return root;
    }
};
// @lc code=end

int main()
{

    Solution sl;

    printTree(sl.flatten(genTree({1, 2, 5, 3, 4, null, 6})));

    return 0;
}
