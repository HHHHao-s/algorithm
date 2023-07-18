#include "s.h"
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        ret[0].push_back(1);
        for(int i=1;i<numRows;i++){
            ret[i].push_back(1);
            for(int j=1;j<i;j++){
                ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            ret[i].push_back(1);
        }
        return ret;
    }
};
// @lc code=end

