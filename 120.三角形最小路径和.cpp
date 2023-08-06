#include "s.h"
/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> fk(n,0);
        vector<int> sb(n,0);
        fk[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            sb[0] = fk[0]+triangle[i][0];

            for(int j=1;j<i;j++){
                
                sb[j] = min(fk[j-1], fk[j]) + triangle[i][j];
            }

            sb[i] = fk[i-1]+triangle[i][i];

            fk = sb;
        }

        int ans=100000000;
        for(int i=0;i<n;i++){
            ans = min(ans, fk[i]);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<vector<int>> triangle = {
    //     {2},
    //     {3,4},
    //     {6,5,7},
    //     {4,1,8,3}
    // };
    vector<vector<int>> triangle = {
        {2},

    };
    cout << s.minimumTotal(triangle);

    return 0;
}