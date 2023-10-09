#include "s.h"
/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
    int limit;
    int find_max(TreeNode* node, int sum){

        int left=INT_MIN,right=INT_MIN;
        if(node->left==nullptr && node->right==nullptr){

            return sum+node->val;
        }
        if(node->left){
            left = find_max(node->left, sum+node->val);
            if(left<limit){
                node->left=nullptr;
            }

        }
        if(node->right){
            right = find_max(node->right, sum+node->val);      
            if(right<limit){
                node->right = nullptr;
            }
        }       
        
        return max(left, right);

    }

public:
    TreeNode* sufficientSubset(TreeNode* root, int limit_) {
        limit = limit_;

        int ret = find_max(root, 0);
        if(ret<limit){
            root=nullptr;
        }
        return root;

    }
};
// @lc code=end

int main(){

    TreeNode *root =genTree({
        1,2,-3,-5,null,4,null
    });

    Solution s;
    printTree(s.sufficientSubset(root, -1));


    return 0;
}