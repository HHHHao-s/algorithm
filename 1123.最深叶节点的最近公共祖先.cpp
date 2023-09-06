#include "s.h"
/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    int max_depth=-1;
    TreeNode* ans;

    int travel(TreeNode *root, int depth){

        
        int a = 0,b=0;
        if(root->right!=nullptr && root->left!=nullptr){
            a = travel(root->left, depth+1);
            b = travel(root->right, depth+1);
            if(a==b&&a==max_depth){
                ans = root;
            }
        }else if(root->left==nullptr && root->right!=nullptr){
            b = travel(root->right, depth+1);
        }else if(root->left!=nullptr && root->right==nullptr){
            a = travel(root->left, depth+1);
        }else{
            if(depth>max_depth){
                max_depth=depth;
                ans = root;
            }
            a=b=depth;
        }
        return max(a,b);

    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        travel(root, 0);
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;

    printTree(s.lcaDeepestLeaves(genTree(
        {1}
    )));


    return 0;
}