#include "../s.h"


class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = 1;
        long long ans = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                dp[i] = dp[i-1] + 1;
                ans += dp[i];
            }else{
                dp[i] = 1;
                ans += dp[i];
            }

        }
        return ans;

    }
};


int main(){
    
}