#include "../s.h"

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<long long> dp1(n);
        vector<long long> dp2(n);
        long long ans=0;
        dp1[0] = nums[0];
        dp2[0] = - 1000000000000000;
        for(int i=1;i<n;i++){

            if(nums[i] < 0){
                dp1[i] = max(dp1[i-1], dp2[i-1])+nums[i];
                dp2[i] = dp1[i-1] - nums[i];
            }else{
                dp1[i] = max(dp1[i-1], dp2[i-1])+nums[i];
                dp2[i] = dp1[i-1] - nums[i];
            }


        }
        return max(dp1[n-1], dp2[n-1]);
    }
};
