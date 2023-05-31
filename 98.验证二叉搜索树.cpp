#include "s.h"
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

    enum LOR{
        LEFT,
        RIGHT
    };

    struct status
    {
        
        int min;
        int max;
        bool true_or_false;
    };
    

    // status myisValidBST(TreeNode *root, int val, enum LOR lor ){
    //     if(root==nullptr) return {val,val,true};

    //     if(lor==LEFT && root->val >= val ){
    //             return {0,0,false}; 
    //     }
    //     if(lor==RIGHT && root->val <= val){
    //             return {0,0,false}; 
    //     }

    //     status tmp1 = myisValidBST(root->left, root->val, LEFT);
    //     status tmp2 = myisValidBST(root->right, root->val, RIGHT);
    //     if(tmp1.max>=root->val || tmp2.min<=root->val || tmp1.true_or_false == false || tmp2.true_or_false==false) return{0,0,false};
            
    //     return {tmp1.min, tmp2.max, true};
    // }

    status myisValidBST(TreeNode *root){
        if(root->left!=nullptr && root->right!=nullptr){
            if(!(root->left->val < root->val && root->right->val > root->val)){
                return {0,0,false};
            }else{
                status tmp1 = myisValidBST(root->left);
                status tmp2 = myisValidBST(root->right);
                if(tmp1.max>=root->val || tmp2.min<=root->val || tmp1.true_or_false == false || tmp2.true_or_false==false) return{0,0,false};
                
                return {tmp1.min,tmp2.max,true};
            }
        }else if(root->left==nullptr && root->right!=nullptr){
            if(!(root->right->val > root->val)){
                return {0,0,false};
            }else{
                status tmp = myisValidBST(root->right);
                if(tmp.min <= root->val || tmp.true_or_false== false) return {0,0,false};

                return {root->val,tmp.max, true};
            }
        }else if(root->left!=nullptr && root->right==nullptr){
            if(!(root->left->val < root->val)){
                return {0,0,false};
            }else{
                status tmp = myisValidBST(root->left);
                if(tmp.max >= root->val || tmp.true_or_false== false) return {0,0,false};

                return {tmp.min,root->val, true};
            }
        }else{
            return {root->val,root->val,true};
        }

    }

    bool isValidBST(TreeNode* root) {
        if(root->left!=nullptr && root->right!=nullptr){
            if(!(root->left->val < root->val && root->right->val > root->val)){
                return false;
            }else{
                status tmp1 = myisValidBST(root->left);
                status tmp2 = myisValidBST(root->right);
                if(tmp1.max>=root->val || tmp2.min<=root->val || tmp1.true_or_false == false || tmp2.true_or_false==false) return false;
                
                return true;
            }
        }else if(root->left==nullptr && root->right!=nullptr){
            if(!(root->right->val > root->val)){
                return false;
            }else{
                status tmp = myisValidBST(root->right);
                if(tmp.min <= root->val || tmp.true_or_false== false) return false;

                return true;
            }
        }else if(root->left!=nullptr && root->right==nullptr){
            if(!(root->left->val < root->val)){
                return false;
            }else{
                status tmp = myisValidBST(root->left);
                if(tmp.max >= root->val || tmp.true_or_false== false) return false;

                return true;
            }
        }else{
            return true;
        }
    }
};
// @lc code=end

int main(){

    Solution sl;
    cout << sl.isValidBST(genTree({5,1,null,0,6}));



    return 0;
}