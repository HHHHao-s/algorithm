#include "s.h"
/*
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */

// @lc code=start
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return 1;
        }
        vector<vector<int>> dp(2, vector<int>(n)); 
        dp[1][n-1] = 1;
        dp[0][n-1] = 1;
        map<int, int> num_to_pos;
        num_to_pos[arr[n-1]] = n-1;
        int ans=1;
        for(int i=n-2;i>=0;i--){
            auto it = num_to_pos.lower_bound(arr[i]);
            if(it==num_to_pos.end()){
                // 没有比他大的
                // 只能偶数跳
                --it;
                dp[0][i] = dp[1][it->second];
                dp[1][i] = 0;
            }else{
                dp[1][i] =dp[0][it->second];
                if(it->first == arr[i]){
                    dp[0][i] = dp[1][it->second];
                }else if( it!=num_to_pos.begin()){
                    // 有更小的，能偶数跳
                    --it;               
                    dp[0][i] = dp[1][it->second];
                }else{
                    dp[0][i] = 0;
                }
            }
            if(dp[1][i]==1){
                ans++;
            }
            num_to_pos[arr[i]]=i;
            
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;

    vector<int> arr ={2,3,1,1,4};
    cout << s.oddEvenJumps(arr);

}