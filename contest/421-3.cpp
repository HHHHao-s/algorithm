#include "../s.h"


class Solution {
public:

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(201,vector<long long>(201, -1)));
        const long long MOD = 1e9+7;
        auto dfs = [&](auto&&dfs, int cur, int i, int j){
            
            if(cur<0){
                // no element
                if(i==j && i==0){
                    return (long long)0;
                }
                return (long long)(i==j);
            }
            if(memo[cur][i][j]!=-1){
                return memo[cur][i][j];
            }
            memo[cur][i][j] = (dfs(dfs , cur-1, i, j)+ dfs(dfs, cur-1, gcd(i, nums[cur]),j )+ dfs(dfs, cur-1, i, gcd(j, nums[cur])))%MOD;
            return memo[cur][i][j];

        };

        auto ans=  dfs(dfs, n-1, 0,0);
        if(ans<0){
            ans+=MOD;
        }
        return ans;

    }
};
