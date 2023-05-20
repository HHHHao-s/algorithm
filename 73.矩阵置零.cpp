#include "s.h"
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int first_row_is_zero = 0;

        int m = matrix[0].size(); // m列
        int n = matrix.size(); // n行

        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                first_row_is_zero = 1;
                break;
            }
        }


        for(int i=n;i-->1;){
            int this_row_is_zero = 0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    this_row_is_zero = 1;
                }
            }
            if(this_row_is_zero){
                for(int j=0;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<n;i++){
                    matrix[i][j] = 0;
                }

            }
        }

        if(first_row_is_zero){
            for(int j=0;j<m;j++){
                       
                matrix[0][j] = 0; 
            }
        }
    }
};
// @lc code=end

