#include "s.h"
/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder,unordered_map<int,int>& pre, 
                    unordered_map<int,int>& post, int l, int r){

        if(l==r){
            return new TreeNode(preorder[l]);
        }else if(l>r){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[l]);
        int x = preorder[l];
        int xi = post[x];
        root->left = build(preorder, postorder, pre, post, l+1, pre[postorder[xi-1]]-1);
        root->right = build(preorder, postorder, pre, post, pre[postorder[xi-1]], r);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        unordered_map<int,int> post, pre;
        for(int i=0;i<postorder.size();i++){
            post[postorder[i]] = i;
            pre[preorder[i]] = i;
        }

        return build(preorder, postorder, pre, post, 0, preorder.size()-1);
        
        

    }
};
// @lc code=end

int main(){
    vector<int> a = {1,2,4,5,3,6,7},b = {4,5,2,6,7,3,1};
    Solution s;
    printTree(s.constructFromPrePost(a, b));
}