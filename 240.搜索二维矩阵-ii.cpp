#include "s.h"
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#define GET matrix[y][x]
class Solution {
public:

  

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m= matrix[0].size();
        int x = m-1, y=0;
        while(x>=0 && y<n){
            if(GET>target){
                // 不在这列了
                x--;
            }
            else if(GET<target){
                // 不在这行
                y++;
            }else{
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

