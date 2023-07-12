#include "s.h"
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:

    int m,n;

    int at(const vector<vector<int>>& matrix, int k){
        return matrix[k/n][k%n];
    }

    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();

        int i=0,j=m*n-1;

        while(i<=j){
            int mid = (j+i)/2;
            // int at_i = at(matrix, i);
            int at_mid = at(matrix, mid);
            // int at_j = at(matrix, j);

            if(at_mid>target){
                j = mid-1;

            }else if(at_mid == target){
                return true;
            }else{
                i = mid+1;
            }



        }

        return false;
    }
};
// @lc code=end

inline int at(const vector<vector<int>>& matrix, int k){
    return matrix[k/matrix[0].size()][k%matrix[0].size()];
}
int main(){

    Solution s;

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    // 遍历matrix
    // for(int i=0;i<matrix.size();i++){
    //     for(int j=0;j<matrix[i].size();j++){
    //         cout << s.searchMatrix(matrix,matrix[i][j]);
    //     }
    // }

    cout << s.searchMatrix({{1,1}}, 0);
    


    return 0;
}
