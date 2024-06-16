
#include "../s.h"

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        
        vector<int> susu(101, 1);
        susu[1] = 0;
        for(int i=2;i<=100;i++){
            for(int j=2;j<i;j++){
                if(i%j==0){
                    susu[i] = 0;
                    break;
                }
            }
        }
        int l = INT_MAX;
        int r = -1;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            if(susu[num]){
                l = min(l,i);
                r= max(r,i);
            }

        }

        return r-l;

    }
};