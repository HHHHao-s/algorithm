#include "s.h"

/*
 * @lc app=leetcode.cn id=3143 lang=cpp
 *
 * [3143] 正方形中的最多点数
 */

// @lc code=start
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
       
        map<int,vector<int>> m;

        for(int i=0;i<points.size();i++){
            m[max(abs(points[i][0]), abs(points[i][1]))].push_back(s[i]-'a');
        }

        int all = 0;
        vector<int> cnt(26);
        for(const auto &[len, se]:m ){
            int last = all;
            for(auto each_p : se){
                cnt[each_p]++;
                all++;
                if(cnt[each_p] > 1){
                    return last;
                }
            }
            

        }
        return all;
    

    }
};
// @lc code=end

