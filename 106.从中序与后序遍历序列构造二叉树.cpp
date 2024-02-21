#include "s.h"
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(const vector<int>& inorder,const  vector<int>& postorder) {

        int n = inorder.size();

        unordered_map<int,int> pos;

        for(int i=0;i<n;i++){
            pos[inorder[i]] = i;
        }

        function<TreeNode*(int ,int ,int)> f = [&](int index, int l, int r){

            if(l==r){
                return new TreeNode(inorder[l]);
            }else if(l>r){
                TreeNode *ret = nullptr;
                return ret;
            }

            TreeNode *node = new TreeNode(postorder[index]);
            int position = pos[node->val];
            int rnodes = r-pos[node->val];
            int lindex = index - rnodes-1;
            node->left = f(lindex, l, position-1);
            node->right = f(index-1, position+1, r);
            return node;
        };

        return f(n-1, 0, n-1);

    }
};
// @lc code=end

int main(){
    Solution s;
    printTree(s.buildTree({3,2,1},{3,2,1}));
}