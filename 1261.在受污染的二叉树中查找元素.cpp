#include "s.h"
/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    unordered_set<int> mp;

    FindElements(TreeNode* root) {
        root->val = 0;
        function<void(TreeNode*)> dfs= [&](TreeNode* node){
            mp.insert(node->val);
            if(node->left){
                node->left->val = node->val *2+1;
                dfs(node->left);
            }
            if(node->right){
                node->right->val = node->val *2 +2;
                dfs(node->right);
            }

        };

        dfs(root);

    }
    
    bool find(int target) {
        return mp.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

