#include "s.h"


class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cros=0;
        int zeros=0;
        for(int x:nums){
            if(x&1==1){
                ;
            }else{
                zeros++;
                if(zeros==2){
                    return true;
                }
            }
        }
        return false;

    }
};