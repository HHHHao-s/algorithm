#include "s.h"
/*
 * @lc app=leetcode.cn id=3148 lang=cpp
 *
 * [3148] 矩阵中的最大得分
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        
        int m =grid.size();
        int n = grid[0].size();

        vector<long long > fuck1(m, INT_MIN), fuck2(n,INT_MIN);
        long long ret = INT_MIN;



        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    fuck2[0]= fuck1[0] = -grid[i][j];
                    
                    continue;
                }
                long long big = INT_MIN;
                
                big = max(big, grid[i][j]+fuck1[i]);
                big = max(big , grid[i][j]+ fuck2[j]);
                
                ret = max(ret, big);
                fuck1[i] = max({fuck1[i], big-grid[i][j],(long long) -grid[i][j]});
                fuck2[j] = max({fuck2[j], big-grid[i][j],(long long)-grid[i][j]});

            }
        }
        return ret;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> a={{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    cout<<s.maxScore(a);
}