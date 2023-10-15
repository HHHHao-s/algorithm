#include "../s.h"

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        
        int n = nums.size();
        for(int j=0;j<n;j++){
            for(int i=j+indexDifference;i<n;i++){
                if(abs(nums[i]-nums[j])>=valueDifference){
                    return {j,i};
                }
            }
        }
        return {-1,-1};

    }
};