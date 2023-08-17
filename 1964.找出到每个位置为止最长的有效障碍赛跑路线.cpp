#include "s.h"
/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
 */

// @lc code=start
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<int> ans;
        vector<int> dp;


        dp.push_back(obstacles[0]);
        ans.push_back(1);
        for(int i=1;i<n;i++){
            int x = obstacles[i];

            if(x>=dp.back()){
                dp.push_back(x);
                ans.push_back(dp.size());
            }else{
                int pos = upper_bound(dp.begin(), dp.end(), x)-dp.begin();
                ans.push_back(pos+1);
                dp[pos] = x;
            }
        
        }
       
        return ans;
    }
};
// @lc code=end

int main() {
    
    Solution s;

    vector<int> obstacles = {
        5,1,5,5,1,3,4,5,1,4
    };

    printArr(s.longestObstacleCourseAtEachPosition(obstacles));

    return 0;
}