#include "../s.h"


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> ret;
        vector<int> a1, a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(a1.back() > a2.back()){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
        }
        ret = a1;
        for(int a:a2){
            ret.push_back(a);
        }
        return ret;

    }
};