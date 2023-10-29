#include "../s.h"

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        
        vector<int> each(32);
        int ret=0;
        for(int x:nums){
            for(int i=0;i<32;i++){
                if(x&(1<<i)){
                    each[i]++;
                }
                
            }
        }
        for(int i=0;i<32;i++){
            if(each[i]>=k){
                ret |= (1<<i);
            }
        }
        return ret;

    }
};