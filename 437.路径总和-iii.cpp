#include "s.h"
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start

class Solution
{
public:

    long long target = 0;
    unordered_map<long long, int> prefix = {};
    int dfs(TreeNode *root, long long curr){
        if(root==nullptr) return 0;
        
        int ret = 0;
        curr = curr+root->val;

        if(prefix.count(curr-target)==1){
            ret = prefix[curr-target];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr);
        ret += dfs(root->right, curr);
        prefix[curr]--;


        return ret;

    }

    int pathSum(TreeNode *root, long long targetSum)
    {
        prefix[0] = 1;
        target = targetSum;
        return dfs(root,0 );
    }
};
// @lc code=end

int main()
{

    Solution sl;
    sl.pathSum(genTree({10, 5, -3, 3, 2, null, 11, 3, -2, null, 1}), 8);

    return 0;
}
