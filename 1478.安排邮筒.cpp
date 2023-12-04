#include "s.h"
/*
 * @lc app=leetcode.cn id=1478 lang=cpp
 *
 * [1478] 安排邮筒
 */

// @lc code=start
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {

        sort(houses.begin(), houses.end());
        int n = houses.size();
        if(n==k){
            return 0;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, 100000000)));
        for(int i=0;i<n;i++){
            dp[i][i][1] = 0;
        }
        for(int i=n-2;i>=0;i--){

                
            for(int j=i+1;j<n;j++){
                if(i==j-1){
                    dp[i][j][1] = houses[j]-houses[i];
                }else{
                    dp[i][j][1] = dp[i+1][j-1][1]+houses[j]-houses[i];
                }
                
            }
        }
        for(int kk=2;kk<=k;kk++){
            for(int i=n-kk;i>=0;i--){

                for(int j=i;j<=n-kk;j++){
                    
                    dp[i][n-1][kk]  = min(dp[i][j][1]+ dp[j+1][n-1][kk-1],dp[i][n-1][kk]);
                   
                    
                }
            }
        }
        return dp[0][n-1][k];

    }
};
// @lc code=end

int main(){

    Solution s;
    vector< int> hourse = {2,3,5,12,18};
    cout << s.minDistance(hourse, 2);
}