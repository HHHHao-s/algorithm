#include "../s.h"

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        map<int ,int >ct;

        for(int p: power){
            ct[p]++;
        }
        vector<pair<long long,long long>> each;

        for(auto [p, c]: ct){
            each.push_back({p,c});
        }

        int n = each.size();
        vector<vector<long long>> dp(2, vector<long long>(n));
        
        dp[0][0] = 0;
        dp[1][0] = each[0].first*each[0].second;

        if(n==1){
            return dp[1][0];
        }
        dp[0][1] = dp[1][0];
        if(each[0].first < each[1].first-2){
            dp[1][1] = dp[1][0]+each[1].first*each[1].second;
        }else{
            dp[1][1] = each[1].first*each[1].second;
        }
    
        for(int i=2;i<n;i++){

            long long last = each[i-1].first;
            long long ll = each[i-2].first;
            long long cur = each[i].first;
            long long mx_0;
            long long mx_1;
            if(cur-2>last){
                mx_1 = each[i].first*each[i].second + max(dp[1][i-1], dp[0][i-1]);
                mx_0 = max(dp[1][i-1], dp[0][i-1]);
            }else if(cur-2<= last && cur-2>ll){
                mx_0 = max({dp[1][i-1], dp[0][i-1], dp[1][i-2], dp[0][i-2]});
                mx_1 = max({dp[0][i-2],dp[1][i-2], dp[0][i-1]}) + each[i].first*each[i].second;
            }else{
                mx_0 = max({dp[1][i-1], dp[0][i-1], dp[1][i-2], dp[0][i-2]});
                if(i<3){
                    mx_1 = each[i].first*each[i].second;
                }else{
                    mx_1 = max(dp[0][i-3],dp[1][i-3]) + each[i].first*each[i].second;
                }  
            }

            

            dp[0][i] = mx_0;
            dp[1][i] = mx_1;
        }


        return max(dp[0][n-1], dp[1][n-1]);


    }
};