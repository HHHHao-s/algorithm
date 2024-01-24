#include "s.h"
/*
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<vector<int>> dp(k, vector<int>(1<<n,-1));

        vector<int> cmemo(1<<n, -1);
        cmemo[0] = 0;
        cmemo[1] = jobs[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<(1<<i);j++){
                cmemo[(1<<i)|j] = cmemo[j]+jobs[i];
            }
        };
        for(int i=0;i<(1<<n);i++){
            dp[0][i] = cmemo[i];
        }

        int cur = 0;
        for(int i=1;i<k;i++){
            for(int j=0;j<(1<<n);j++){
                int mmin = INT_MAX;
                for(int x=j;x;x=(x-1)&j){ // 求子集
                    mmin = min(mmin, max(dp[i-1][j-x], cmemo[x]));
                }
                dp[i][j] = mmin;
            }
        }

        return dp[k-1][(1<<n)-1];

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> jobs={1,2,4,7,8};
    cout<< s.minimumTimeRequired(jobs,2);
}