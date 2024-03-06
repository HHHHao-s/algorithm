#include "s.h"
/*
 * @lc app=leetcode.cn id=2122 lang=cpp
 *
 * [2122] 还原原数组
 */

// @lc code=start
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        
        
        for(int i=1;i<n;i++){
            vector<int >ans;
            auto tmp = nums;
            if((nums[i]-nums[0]) %2==0 && nums[i]-nums[0]!=0){
                int k= nums[i]-nums[0];
                int l = 0;
                int r = i;
                
                while(r<n){
                    while( l< n && nums[l]==0 ){
                        l++;
                    }
                    while ( r< n && (nums[r]==0 || nums[r]-nums[l]<k))
                    {
                        r++;
                    }
                    if(r<n && l < n && (nums[r]-nums[l]==k)){
                        ans.push_back((nums[l]+nums[r])/2);
                        nums[l] = 0;
                        nums[r] = 0;
                        l++;
                        r++;
                    }else if(r<n && l < n && (nums[r]-nums[l]>k)){
                        break;
                    }
                    
                }
            }
            nums = tmp;
            
            if(ans.size()==n/2){
                return ans;
            }
            
        }
        return {};


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1,50,99,101,150,199};
    s.recoverArray(nums);
}