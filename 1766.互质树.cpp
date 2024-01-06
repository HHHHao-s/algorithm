#include "s.h"
/*
 * @lc app=leetcode.cn id=1766 lang=cpp
 *
 * [1766] 互质树
 */

// @lc code=start
class Solution {
private:
    vector<int> ans;
    vector<vector<int>> grid;
    void dfs(vector<int>& nums, int node, int num, int far, int far_num, int par){

        if(num == nums[node]){
            ans[node] = far;
        }
        if(gcd(num, nums[node])==1){
            far = node;
            far_num=nums[node];
        }
        for(int next: grid[node]){
            if(par!=next){
                dfs(nums, next, num, far, far_num, node);
            }
        }

    }

public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        grid.resize(n);
        ans.resize(n);
        for(auto &edge: edges){
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
        }
        for(int i=1;i<=50;i++){
            dfs(nums, 0, i,-1,-1,-1);

        }

        return ans;


    }
};
// @lc code=end

