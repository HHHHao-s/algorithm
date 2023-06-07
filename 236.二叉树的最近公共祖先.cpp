#include "s.h"  
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<int, bool> map;
    bool find_p=0,find_q=0;
    TreeNode* ret= nullptr;

    // int num_ret = INT32_MAX;
    // void dfs(TreeNode *root,int p, int q){
    //     if(ret!=nullptr) return;
    //     if(root== nullptr) return ;
    //     int cp=find_p, cq= find_q;
    //     if(root->val == p){
    //         find_p = 1;
    //     }
    //     if(root->val == q){
    //         find_q = 1;
    //     }

    //     dfs(root->left, p,q);
    //     dfs(root->right, p,q);
    //     if(!cp && !cq && find_p && find_q && num_ret==INT32_MAX)
    //         num_ret = root->val;

    // }


    void dfs(TreeNode *root,TreeNode* p, TreeNode* q){
        if(ret!=nullptr) return;
        if(root== nullptr) return ;
        int cp=find_p, cq= find_q;
        if(root == p){
            find_p = 1;
        }
        if(root == q){
            find_q = 1;
        }

        dfs(root->left, p,q);
        dfs(root->right, p,q);
        if(!cp && !cq && find_p && find_q && ret==nullptr)
            ret = root;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p,q);

        return ret;
    }
};
// @lc code=end


int main(){

    Solution sl;
    // sl.dfs(genTree({3,5,1,6,2,0,8,null,null,7,4} ), 1,0);
    // cout << sl.num_ret;

    return 0;
}
