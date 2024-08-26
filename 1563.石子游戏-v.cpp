#include "s.h"
/*
 * @lc app=leetcode.cn id=1563 lang=cpp
 *
 * [1563] 石子游戏 V
 */

// @lc code=start
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();
        if(n==1){
            return 0;
        }

        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));

        vector<int > presum(n+1);
        for(int i=0;i<n;i++){
            presum[i+1] = presum[i] + stoneValue[i];
        }

        auto dfs = [&](auto&&dfs, int l, int r){

            if(l==r){
                return 0;
            }
            if(memo[l][r]!=-1){
                return memo[l][r];
            }
            
            int ret = 0;
            int all = presum[r+1] - presum[l];
            for(int i=l;i<r;i++){
                int lv = presum[i+1] - presum[l];
                int rv = all - lv;
                if(lv>rv){
                    ret = max(ret, rv + dfs(dfs , i+1, r));

                }else if(lv==rv){
                    ret = max(ret, lv + max(dfs(dfs, l, i), dfs(dfs,i+1,r)));

                }else {
                    ret = max(ret,lv + dfs(dfs, l, i));
                }


            }
            memo[l][r] = ret;   
            return ret;

        };

        return dfs(dfs ,0, n-1);



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> sv = {6,2,3,4,5,5};
    s.stoneGameV(sv);
}