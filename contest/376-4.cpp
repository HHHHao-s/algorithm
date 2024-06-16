#include "../s.h"

class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> presum;
        presum.push_back(nums[0]);
        for(int i=1;i<n;i++){
            presum.push_back(nums[i]);
            presum[i]+=presum[i-1];
        }
        long long ans = 1;
        for(long long l=0,r=1;r<n;r++){

            long long mid = (l+r)/2;
            long long need= (long long)nums[mid]*(mid-l+1)-(presum[mid]-(l>0?presum[l-1]:0))+(presum[r]-presum[mid])-(long long)nums[mid]*(r-mid);
            while(need>k && l<r){
                l++;
                mid = (l+r)/2;
                need= (long long)nums[mid]*(mid-l+1)-(presum[mid]-(l>0?presum[l-1]:0))+(presum[r]-presum[mid])-(long long)nums[mid]*(r-mid);
            }
            if(need<=k){
                ans = max(r-l+1, ans);
            }
        }
        return ans;

    }
};


int main(){

    Solution s;
    vector<int> nums={1,4,4,2,4};
    cout << s.maxFrequencyScore(nums,0);
}