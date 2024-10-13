#include "../s.h"


class Solution {
public:
    int countWinningSequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(3, vector<int>(2*n+2));

        int MOD = 1e9+7;

        if(s[0]=='F'){

            dp[1][n+1] = 1;
            dp[0][n] = 1;
            dp[2][n-1] =1;
        }else if(s[0]=='W'){
            dp[1][n] = 1;
            dp[0][n-1] = 1;
            dp[2][n+1] =1;
        }else{
            dp[1][n-1] = 1;
            dp[0][n+1] = 1;
            dp[2][n] =1;
        }

        for(int i=1;i<n;i++){
            vector<vector<int>> ndp(3, vector<int>(2*n+2));
            for(int j=1;j<=2*n;j++){

                if(s[i]=='F'){

                    ndp[0][j] = (dp[1][j] +dp[2][j])%MOD;
                    ndp[1][j] = (dp[0][j-1]+dp[2][j-1])%MOD;
                    ndp[2][j] = (dp[0][j+1] + dp[1][j+1])%MOD;
                }else if(s[i]=='W'){
                    ndp[0][j] = (dp[1][j+1] +dp[2][j+1])%MOD;
                    ndp[1][j] = (dp[0][j] +dp[2][j])%MOD;
                    ndp[2][j] = (dp[0][j-1] + dp[1][j-1])%MOD;
                }else{
                    ndp[0][j] = (dp[1][j-1] + dp[2][j-1])%MOD;
                    ndp[1][j] = (dp[0][j+1]   + dp[2][j+1])%MOD;
                    ndp[2][j] = (dp[0][j] + dp[1][j])%MOD;
                }

            }
            dp = move(ndp);
        }
        int ans= 0;
        for(int i=n+1;i<=2*n;i++){

            ans= (ans+dp[0][i])%MOD;
            ans= (ans+dp[1][i])%MOD;
            ans= (ans+dp[2][i])%MOD;
        }
        if(ans<0){
            ans+=MOD;
        }
        return ans;


    }
};

int main(){
    cout <<Solution().countWinningSequences("FFF");
}