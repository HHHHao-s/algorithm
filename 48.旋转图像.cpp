#include "s.h"
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int x,x2;
        int n = matrix[0].size(), k = n;
        int bia = 0;
        while(k>1){
            for(int i=0;i<k-1;i++){
                x = matrix[bia+i][ n-1 - bia];
                matrix[bia+i][n-1-bia] = matrix[bia][bia +i];

                x2 = matrix[n-1-bia][n-i-1-bia];
                matrix[n-1-bia][n-i-1-bia]=x;

                x = matrix[n-i-1-bia][bia];
                matrix[n-i-1-bia][bia] = x2;

                matrix[bia][bia +i] = x;

            }
            k-=2;
            bia++;

        }
        

    }
};
// @lc code=end

int main(){

    Solution sl;

    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    sl.rotate(matrix);
    
    int n = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
    }

}