#include "s.h"
/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 *
 * [2477] 到达首都的最少油耗
 */

// @lc code=start
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        vector<vector<int>> g(roads.size() + 1);
        for (auto &e: roads) {
            int x = e[0], y = e[1];
            g[x].push_back(y); // 记录每个点的邻居
            g[y].push_back(x);
        }

        long long ans = 0;
        function<int(int, int)> dfs = [&](int x, int fa) -> int {
            int size =1;
            for(int i=0;i<g[x].size();i++){
                if(fa!=g[x][i]){
                    size +=dfs(g[x][i], x);
                    
                }

            }
            if (x) { // x 不是根节点
                ans += (size - 1) / seats + 1; // ceil(size/seats)
            }
            
            
            return size;
        };
        dfs(0, -1);
        return ans;
    }
};

// @lc code=end

int main(){

    Solution s;
    vector<vector<int>> roads={
        {0,1},
        {0,2},
        {1,3},
        {1,4}
    };
    cout << s.minimumFuelCost(roads, 5);
}