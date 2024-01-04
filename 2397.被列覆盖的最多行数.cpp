#include "s.h"
/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> eachs;
        for(int i=0;i<m;i++){
            int each=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    each |= 1<<(n-j-1);
                }
            }
            eachs.push_back(each);
        }
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            int cnt =0 ;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    cnt++;
                }
            }
            if(cnt!=numSelect){
                continue;
            }
            cnt = 0;
            for(int j=0;j<m;j++){
                if((eachs[j]&i) == eachs[j]){
                    cnt++;
                }
            }
            ans = max(ans, cnt);

        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> matrix={
        {0,0,0},
        {1,0,1},
        {0,1,1},
        {0,0,1}
    };
    cout << s.maximumRows(matrix, 2);
}