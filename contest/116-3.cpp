#include "../s.h"

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<int> can(target+1);
        
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>target){
                continue;
            }

            for(int j=target-nums[i];j>=1;j--){
                if(can[j]>0){                    
                    can[j+nums[i]] = max(can[j+nums[i]], can[j]+1);                   
                }
            }                     
            can[nums[i]] = max(can[nums[i]],1);
            
        }
        
        return can[target]==0?-1:can[target];

    }
};

int main(){

    Solution s;
    vector<int> nums={9,12,8,4,11,13,15,7,5};
    cout << s.lengthOfLongestSubsequence(nums, 84);
    
}
