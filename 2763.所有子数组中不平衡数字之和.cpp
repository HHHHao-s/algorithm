#include "s.h"
/*
 * @lc app=leetcode.cn id=2763 lang=cpp
 *
 * [2763] 所有子数组中不平衡数字之和
 */

// @lc code=start
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        

        
        int n = nums.size();
        int ans =0;
        
        for(int i=0;i<n;i++){
            vector<int> vis(1010);
            int tmp = 0;
            for(int j=i;j<n;j++){
                int num = nums[j];
                if(!vis[num]){
                    if(vis[num-1] && vis[num+1]){
                        tmp--;
                    }else if(vis[num-1] || vis[num+1]){
                        ;
                    }else{
                        tmp++;
                    }
                    
                }
                ans += tmp-1;
                vis[num] = 1; 
            }
            
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums= {2,3,1,4};
    cout<< s.sumImbalanceNumbers(nums);
}