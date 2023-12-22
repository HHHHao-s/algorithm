#include "s.h"
/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> needforward(n,vector<int>(2,INT_MAX)),needbackward(n,vector<int>(2,INT_MAX)) ;
        int cur=0;
        needforward[0][0] = 1;
        needforward[0][1] = 0;
        for(int i=1;i<n;i++){
            needforward[i][0] = min(needforward[i-1][0], needforward[i-1][1]);
            needforward[i][1] = i;
            for(int j=0;j<i;j++){
                
                if(nums[i]>nums[j]){
                    needforward[i][1] = min(needforward[i][1], needforward[j][1]+i-j-1);
                }
            }
            // if(needforward[i][1]==i-1){
            //     needforward[i][1]=1000000;
            // }
        }
        needbackward[n-1][0] = 1;
        needbackward[n-1][1] = 0;
        int ans =INT_MAX;
        for(int i=n-2;i>=0;i--){
            needbackward[i][0] = min(needbackward[i+1][0], needbackward[i+1][1]);
            needbackward[i][1] = n-i-1;
            for(int j=n-1;j>i;j--){
                
                if(nums[i]>nums[j]){
                    needbackward[i][1] = min(needbackward[i][1], needbackward[j][1]+j-i-1);
                }
            }
            // if(needbackward[i][1]==n-i-1){
            //     needbackward[i][1]=1000000;
            // }
            if(needforward[i][1]!=i && needbackward[i][1]!=n-i-1)
                ans = min(ans ,needbackward[i][1]+needforward[i][1]);
        }
        
        
        return ans;



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {
        100,92,89,77,74,66,64,66,64
    };
    cout << s.minimumMountainRemovals(nums);
}