#include "../s.h"


class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        double m = 10000000000;
        int n = nums.size();
        for(int i=0;i<n/2;i++){
            m = min(m , (nums[i] + nums[n-1-i])/2.0);
        }

        return m;

    }
};