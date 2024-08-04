#include "s.h"
/*
 * @lc app=leetcode.cn id=2188 lang=cpp
 *
 * [2188] 完成比赛的最少时间
 */

// @lc code=start
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        
        vector<vector<long long>> a(tires.size(), vector<long long>(18,0));
        vector<long long> t(18,INT_MAX);
        int i =0;
        for(const auto&each: tires) {
            
            long long f = each[0];
            long long r = 1;

            for(int j=1;j<18;j++){
                if(f*r>=changeTime+f){
                    r= each[1];
                    a[i][j] = a[i][j-1] + changeTime+f;
                }else{
                    a[i][j] = a[i][j-1] +f*r;
                    r*=each[1];
                }
                t[j]=min(t[j], a[i][j]);
            }
            i++;

        }

        vector<long long >dp(numLaps+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<=numLaps;i++){

            for(int j = max(i-17,0);j<i;j++){

                dp[i] = min(dp[j]+t[i-j]+changeTime, dp[i]);

            }


        }

        return dp[numLaps] - changeTime;


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>  > t={{2,3},{3,4}};
    cout << s.minimumFinishTime(t, 5 ,4);
}