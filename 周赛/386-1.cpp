#include "../s.h"

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        unordered_map<int,int> cnt;

        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]]>=3){
                return false;
            }
        }
        return true;

    }
};