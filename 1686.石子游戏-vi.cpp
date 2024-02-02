#include "s.h"
/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 *
 * [1686] 石子游戏 VI
 */

// @lc code=start
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i] = {aliceValues[i]+bobValues[i], i};
        }
        sort(arr.begin(),arr.end(), greater<>());
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                a+=aliceValues[arr[i].second];
            }else{
                b+=bobValues[arr[i].second];
            }
        }
        if(a>b){
            return 1;
        }else if(a==b){
            return 0;
        }
        return -1;

    }
};
// @lc code=end

