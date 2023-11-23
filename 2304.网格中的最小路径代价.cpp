#include "s.h"
/*
 * @lc app=leetcode.cn id=2304 lang=cpp
 *
 * [2304] 网格中的最小路径代价
 */

// @lc code=start
class Solution {

private:
    unordered_map<int,int   > memo;
    int get(int node, int floor,vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        if(memo.count(node)){
            return memo[node];
        }
        if(floor==grid.size()-1){
            return node;
        }
        int ret = INT_MAX;
        int next_floor = floor+1;
        for(int i=0;i<grid[0].size();i++){
            int next = get(grid[next_floor][i], next_floor, grid, moveCost)+moveCost[node][i];
            ret = min(ret, next);
        }
        ret+=node;

        memo[node] = ret;
    
        return ret;

    }

public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int ret = INT_MAX;
        int next_floor = 0;
        for(int i=0;i<grid[0].size();i++){
            int next = get(grid[next_floor][i], next_floor, grid, moveCost);
            ret = min(ret, next);
        }
        return ret;
        

    }
};
// @lc code=end

