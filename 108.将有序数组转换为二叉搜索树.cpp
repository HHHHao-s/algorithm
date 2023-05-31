#include "s.h"
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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


    TreeNode* mysort(vector<int>&nums, int begin, int end){
        if(end-begin==1){
            return new TreeNode(nums[begin]);
        }
        if(end-begin==2){
            return new TreeNode(nums[begin+1],new TreeNode(nums[begin]), nullptr);
        }

        int mid = begin + (end-begin)/2;
        return new TreeNode(nums[mid],mysort(nums,begin,mid),mysort(nums,mid+1,end));
    
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        



        return mysort(nums,0,nums.size());

    }
};
// @lc code=end

int main(){

    Solution sl;

    sl.sortedArrayToBST({-10,-3,0,5,9});




    return 0;
}