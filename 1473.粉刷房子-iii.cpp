#include "s.h"
/*
 * @lc app=leetcode.cn id=1473 lang=cpp
 *
 * [1473] 粉刷房子 III
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        int memo[110][110][25];
        for (int i = 0; i < 110; ++i) {
            for (int j = 0; j < 110; ++j) {
                for (int k = 0; k < 25; ++k) {
                    memo[i][j][k] = -2;
                }
            }
        }

        
        auto dfs = [&](auto &&dfs, int index, int block, int last){

            if(block<0){
                return -1;
            }

            if(index >=m){
                if(block==0){
                    return 0;
                }else{
                    return -1;
                }
            }
            if(memo[index][block][last]!=-2){
                return memo[index][block][last];
            }

            if(houses[index]!=0){

                memo[index][block][last] = dfs(dfs,index+1, last==houses[index]?block:block-1, houses[index]);

                return memo[index][block][last];



            }else{
                int mn = INT_MAX;

                for(int j=0;j<n;j++){
                    

                    int r = dfs(dfs, index+1, last == j+1 ? block: block-1, j+1);
                    if(r!=-1){
                        mn = min(r+ cost[index][j], mn);
                    }

                }
                if(mn==INT_MAX){
                    memo[index][block][last] = -1;
                    return -1;
                }else{
                    memo[index][block][last] = mn;
                    return mn;
                }

            }
            return -1;

        };

        return dfs(dfs, 0, target, n+2);


    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> h = {0,2,1,2,0};
    vector<vector<int>> c ={{1,10},{10,1},{10,1},{1,10},{5,1}};

    cout<< s.minCost(h,c,5,2,3);

}