#include "s.h"
/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 *
 * [2522] 将字符串分割成值不超过 K 的子字符串
 */

// @lc code=start
// class Solution {
// public:
//     int minimumPartition(string s, int k) {
//         int n=s.size();
//         vector<long long> dp(n+1, INT_MAX);
//         dp[0] = 0;


//         for(int i=1;i<=n;i++){
//             long long cur=0;
//             long long tens=1;
//             for(int j=i-1;j>=0;j--){
//                 cur += tens*(s[j]-'0');
//                 if(cur>k){
//                     if(dp[i]==INT_MAX){
//                         return -1;
//                     }
//                     break;
//                 }else{
//                     dp[i] = min(dp[j]+1, dp[i]);
//                     tens*=10;
//                 }
//             }
//         }

//         return dp[n];


//     }
// };
class Solution {
public:
    int minimumPartition(string s, int k)
    {
        long long count = 0;
        long long sum = 0;
        //看有无大于k的，有大于k的直接跳出
        for (char a : s)
        {
            if (a - '0' > k)
            {
                return -1;
            }
            sum = sum * 10 + (a - '0');
            if (sum > k)
            {
                sum = a - '0';
                count++;
            }
        } 
        return count + 1;
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.minimumPartition("165462", 20);
    cout << s.minimumPartition("238182", 5);

    return 0;
}