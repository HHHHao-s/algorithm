#include "../s.h"


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        int last = -1;
        for(int num:nums){
            if(num%2==1){
                if(last == -1){
                    last = 1;
                }else{
                    if(last == 1){
                        return false;
                    }
                }
                last = 1;
            }else{
                if(last == -1){
                    last = 0;
                }else{
                    if(last == 0){
                        return false;
                    }
                }
                last = 0;
                

            }
        }
        return true;

    }
};