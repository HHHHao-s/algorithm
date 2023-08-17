#include "s.h"
/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &v1, const vector<int> &v2){
            return v1[0] < v2[0] || (v1[0]==v2[0] && v1[1] > v2[1]);
        });

        vector<int> dp;
        int n = envelopes.size();
        dp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            int x = envelopes[i][0];
            int y = envelopes[i][1];    

            if(y>dp.back()){
                dp.push_back(y);
            }else{
                int pos = lower_bound(dp.begin(), dp.end(), y) - dp.begin();
                dp[pos] = y;
            }
                   
        }
        return dp.size();

    }
};
// @lc code=end

int main(){
    Solution s;

    // test case
    vector<vector<int>> vec{
        {5,4},
        {5,3},
        {6,4},
        {6,7},
        {2,3},
        {2,3},
        {7,4},
        {7,5}
    };

    cout << s.maxEnvelopes(vec);

    return 0;
}