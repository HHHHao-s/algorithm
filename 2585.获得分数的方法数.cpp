#include "s.h"
/*
 * @lc app=leetcode.cn id=2585 lang=cpp
 *
 * [2585] 获得分数的方法数
 */

// @lc code=start
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int MOD = 1e9+7;

        int n = types.size();
        vector<vector<int>> f(n, vector<int>(target+1));
        for(int i=0;i<=types[0][0];i++){
            if(i*types[0][1]<=target)
                f[0][i*types[0][1]] = 1;
        }

        for(int i=1;i<n;i++){
            f[i] = f[i-1];
            for(int j=1;j<=types[i][0];j++){
                for(int k=0;k<=target;k++){
                    if(j*types[i][1]+k<=target){
                        f[i][j*types[i][1]+k] = (f[i][j*types[i][1]+k]+f[i-1][k]) % MOD;
                    }
                }
                
            }
        }

        return f[n-1][target];

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> types={
        {6,1},
        {3,2},
        {2,3}
    };
    cout << s.waysToReachTarget(6, types);
}