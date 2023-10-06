#include "s.h"
/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
 */

// @lc code=start

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int suppose = 1;
        bool end = false;
        while(!q.empty()){
            int n = q.size();
            if(!end && suppose!=n){
                return false;
            }
            for(int i=0;i<n;i++){
                TreeNode *cur = q.front();
                q.pop();
                if(end == true){
                    if(cur->left != nullptr || cur->right!=nullptr){
                        return false;
                    }
                }else{
                    if(cur->left!=nullptr){
                        q.push(cur->left);
                    }else{
                        end = true;
                        if(cur->right!=nullptr){
                            return false;
                        }
                    }
                    if(cur->right!=nullptr){
                        q.push(cur->right);
                    }else{
                        end = true;
                    }
                }
            }
            suppose*=2;
        }
        return true;

    }
};
// @lc code=end

