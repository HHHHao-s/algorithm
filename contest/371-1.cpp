#include "../s.h"

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(abs(nums[i]-nums[j])<=min(nums[i],nums[j])){
                    ret = max(ret, nums[i]^nums[j]);
                }
            }
        }
        return ret;

    }
};