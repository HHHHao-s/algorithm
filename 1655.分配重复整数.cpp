#include "s.h"
/*
 * @lc app=leetcode.cn id=1655 lang=cpp
 *
 * [1655] 分配重复整数
 */

// @lc code=start
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> cnt;
        for(int num: nums){
            cnt[num]++;
        }
        int n = cnt.size();
        int m = quantity.size();
        vector<vector<bool>> dp(n+1, vector<bool>(1<<m, 0));

        vector<int> each;
        for(auto [num, ct]:cnt){
            each.push_back(ct);
        }
        // 求满足集合s所需要的整数个数
        vector<int> sum(1<<m, 0);
        sum[1] = quantity[0];
        for(int i=1;i<m;i++){
            for(int j=0;j<(1<<i);j++){
                sum[(1<<i)|j] = sum[j]+quantity[i];
            }
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = true;

        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<(1<<m);j++){
                if(dp[i-1][j]){
                    dp[i][j] = true;
                    continue;
                }
                for(int x=j;x;x=(x-1)&j){
                    if(each[i-1]>=sum[x] && dp[i-1][j-x]){
                        dp[i][j] = true;
                        break;
                    }
                    
                }
            }
        }

        return dp[n][(1<<m)-1];

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1,1,2,3};
    vector<int> q={2,2};
    cout<< s.canDistribute(nums ,q );
}