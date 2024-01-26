#include "s.h"
/*
 * @lc app=leetcode.cn id=1591 lang=cpp
 *
 * [1591] 奇怪的打印机 II
 */

// @lc code=start
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        const int COLOR = 61;
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        
        vector<int> up(COLOR, INT_MAX), down(COLOR), left(COLOR, INT_MAX), right(COLOR);
        unordered_set<int> occur;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int color = targetGrid[i][j];
                occur.insert(color);
                up[color] = min(up[color], i);
                down[color] = max(down[color], i);
                left[color] = min(left[color], j);
                right[color] = max(right[color], j);
            }
        }

        unordered_map<int, unordered_set<int>> grid;
        unordered_set<int> zeroIn=occur;
        unordered_map<int,int> inDegree;


        for(int color: occur){
            
            for(int i=up[color];i<=down[color];i++){
                for(int j=left[color];j<=right[color];j++){
                    if(color!=targetGrid[i][j] && !grid[color].count(targetGrid[i][j])){
                        grid[color].insert(targetGrid[i][j]);
                        zeroIn.erase(targetGrid[i][j]);
                        inDegree[targetGrid[i][j]]++;
                    }
                }
            }
        }
        
        function<void(int )> dfs=[&](int node){

            for(auto next: grid[node]){
                inDegree[next]--;
                if(inDegree[next]==0){
                    inDegree.erase(next);
                    dfs(next);
                }
            }

        };
        for(int zi:zeroIn){
            dfs(zi);
        }
        return inDegree.empty();




    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<int>> gird={
        {1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}
    };
    cout <<s.isPrintable(gird);
}
