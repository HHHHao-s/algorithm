#include "s.h"

class Solution {
public:
    int countWays(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int ans=0;
        if(nums[0]!=0){
            ans++;
        }

        for(int i=1;i<nums.size()-1;i++){
            if(i>nums[i-1] && i<nums[i]){
                ans++;
            }

        }
        return ans+1;
    }
};