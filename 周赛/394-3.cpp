#include "../s.h"

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> num(m, vector<int>(10));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                num[i][grid[j][i]]++;
            }
        }

        vector<vector<int>> dp(m, vector<int>(10, INT_MAX));

        for(int i=0;i<10;i++){
            dp[0][i] = n-num[0][i];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    if(j!=k){
                        dp[i][j] = min(dp[i-1][k] + n-num[i][j],dp[i][j] );
                    }
                    
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<10;i++){
            ans = min(ans, dp[m-1][i]);
        }

        return ans;


    }
};