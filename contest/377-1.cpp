#include "../s.h"


class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> ret;
        for(int i=0;i<nums.size();i+=2){
            ret.push_back(nums[i+1]);
            ret.push_back(nums[i]);
        }

        return ret;


    }
};