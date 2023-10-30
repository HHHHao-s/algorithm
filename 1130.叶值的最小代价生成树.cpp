#include "s.h"
/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 */

// @lc code=start
class Solution {
private:
    int ans{0};
    vector<vector<int>> memo;
    int dfs(vector<int> &arr, int l,int r){
        if(l==r){
            return 0;
        }
        if(memo[l][r]!=-1){
            return memo[l][r];
        }
        
        vector<int> tmp(r+1-l);
        int cur_max=0;
        for(int k=r;k>=l;k--){
            cur_max = max(arr[k],cur_max);
            tmp[k-l] = cur_max;

        }
        cur_max=0;
        int res=INT_MAX;
        for(int k=l;k<r;k++){
            cur_max =max(cur_max, arr[k]);
            res = min(res, dfs(arr,l,k)+dfs(arr,k+1,r)+cur_max*tmp[k-l+1]);
        }
        memo[l][r] = res;
        return res;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        memo = vector<vector<int>>(41,vector<int>(41,-1));

        return dfs(arr, 0,arr.size()-1);
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> arr={4,11};
    cout << s.mctFromLeafValues(arr);
}