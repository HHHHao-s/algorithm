#include "s.h"
/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row_emp(m,n),col_emp(n, m);
        vector<pair<int,int>> pos(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pos[mat[i][j]]={i,j};
            }
        } 
        int index=0;
        for(auto x:arr){
            auto [i,j] = pos[x];
            row_emp[i]--;
            col_emp[j]--;
            if(row_emp[i]==0||col_emp[j]==0){
                return index;
            }
            index++;
        }
        return 0;
    }
};
// @lc code=end

