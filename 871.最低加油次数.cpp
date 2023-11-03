#include "s.h"
/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

//         int n = stations.size();

//         vector<long long> dp(n+1);
//         dp[0] = startFuel;
//         for(int i=0;i<n;i++){
//             for(int j=i;j>=0;j--){
//                 if(dp[j]>=stations[i][0]){
//                     dp[j+1] = max(dp[j+1],dp[j]+stations[i][1] );
//                 }
//             }
//         }

//         for(int i=0;i<=n;i++){
//             if(dp[i]>=target){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
// };
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        int n = stations.size();

        int having=startFuel, pre=0;
        priority_queue<long long> pq;
        int ans = 0;
        for(int i=0;i<=n;i++){
            int cur = i==n?target:stations[i][0];
            having -= cur-pre;
            pre = cur;  
            while(having<0 && !pq.empty()){
                having += pq.top();
                pq.pop();
                ans++;
            }
            if(having<0){
                return -1;
            }
            if(i==n){
                break;
            }
            pq.push(stations[i][1]);

        }

        
        return ans;
    }
};

// @lc code=end

