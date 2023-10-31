#include "s.h"
/*
 * @lc app=leetcode.cn id=2003 lang=cpp
 *
 * [2003] 每棵子树内缺失的最小基因值
 */

// @lc code=start
class Solution {

    

public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> g;
        unordered_set<int> vis, having;

        int n;
        n = parents.size();
        g.resize(n);
        ans = vector<int>(n,1);
        for(int i=0;i<n;i++){
            if(parents[i]>=0)
                g[parents[i]].push_back(i);
        }

        function<void(int)> dfs=[&](int node){
            if(vis.count(node)){
                return ;
            }
            vis.insert(node);
            having.insert(nums[node]);
            for(auto next: g[node]){
                dfs(next);
            }
        
        };

        int cur=1,node = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                node = i;
            }
        }

        while(node!=-1){
            dfs(node);
            while(having.count(cur)){
                cur++;
            }
            ans[node] = cur;
            node = parents[node];

        }



        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> parents={-1,0,1,0,3,3},nums={5,4,6,2,1,3};
    printArr(s.smallestMissingValueSubtree(parents, nums));
}