#include "../s.h"

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i+=3){
            vector<int> tmp{nums[i]};

            for(int j=i+1;j<i+3;j++){
                if(abs(nums[j]-nums[i])>k){
                    return {};
                }else{
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;

    }
};