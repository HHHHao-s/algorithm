#include "s.h"
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start

class Solution {
public:

    int ret=-1001;

    int getMaxSum(TreeNode *root){
        if(root==nullptr) return -1001;

        int a = getMaxSum(root->left);
        int b = getMaxSum(root->right);
        int c = a+b+root->val;

        ret = max({a+root->val,b+root->val,c, a,b,ret,root->val});

        return max({a+root->val,b+root->val, root->val});
    }

    int maxPathSum(TreeNode* root) {

        getMaxSum(root);
        return ret;
    }
};

// class Solution {
// private:
//     int maxSum = INT_MIN;

// public:
//     int maxGain(TreeNode* node) {
//         if (node == nullptr) {
//             return 0;
//         }
        
//         // 递归计算左右子节点的最大贡献值
//         // 只有在最大贡献值大于 0 时，才会选取对应子节点
//         int leftGain = max(maxGain(node->left), 0);
//         int rightGain = max(maxGain(node->right), 0);

//         // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
//         int priceNewpath = node->val + leftGain + rightGain;

//         // 更新答案
//         maxSum = max(maxSum, priceNewpath);

//         // 返回节点的最大贡献值
//         return node->val + max(leftGain, rightGain);
//     }

//     int maxPathSum(TreeNode* root) {
//         maxGain(root);
//         return maxSum;
//     }
// };

// @lc code=end

int main(){

    Solution sl;
    cout << sl.maxPathSum(genTree({-10,-9,-6,null,null,-15,-7}));


    return 0;
}