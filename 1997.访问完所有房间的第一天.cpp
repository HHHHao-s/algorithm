#include "s.h"
/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 *
 * [1997] 访问完所有房间的第一天
 */

// @lc code=start
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {

        int n = nextVisit.size();
        vector<long long> presum(n);
        presum[0] = 0;
        vector<long long> dp0(n);
        vector<long long> dp1(n);
        dp1[0] = 0;
        dp0[0] = 1;
        dp1[1] = 2;
        if(n==2){
            return 2;
        }
        presum[1] = 2;
        const long long MOD = 1e9+7;
        for(int i=1;i<n-1;i++){
            dp0[i] = (1+presum[i]-presum[nextVisit[i]]+dp1[i])%MOD;
            dp1[i+1] = (dp0[i]+1)%MOD;
            presum[i+1] = (presum[i]+dp1[i+1]-dp1[i])%MOD; 
        }
        if(dp1[n-1]<0){
            dp1[n-1]+=MOD;
        }
        return (int)dp1[n-1];



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> arr = {0,0,1,3,2,4,0};
    cout << s.firstDayBeenInAllRooms(arr);
}