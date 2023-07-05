#include "s.h"
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:

    void dfs(int num,const vector<int>& nums ,vector<vector<int>>& ret, int n, int first, vector<int>&cur){
        if(num==0){
            ret.emplace_back(cur);
            return ;
        }
        for(int i = first;i<n-num+1;i++){
            cur.push_back(nums[i]);
            dfs(num-1, nums,ret,n,i+1, cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        int n = nums.size();
        vector<int>cur;
        for(int i=1;i<=n;i++){
            dfs(i, nums, ret, n,0, cur);
        }
        return ret;
    }
};
// @lc code=end

int main(){

    Solution s;

    
    print2d(s.subsets({1,2,3}));


    return 0;
}