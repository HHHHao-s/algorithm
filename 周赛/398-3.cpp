#include "../s.h"


class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        
        long long ans = 0;
        long long t = 1;
        for(int i=0;i<9;i++){
            vector<long long> each(10);
            for(long long num:nums){
                
                each[(num/t) % 10]++;

            }

            for(int j=0;j<=9;j++){
                for(int k=j+1;k<=9;k++){
                    
                    ans += each[j]*each[k];
                    
                }
            }
            t*=10;
            if(t>(long long)nums[0]){
                break;
            }
        }

        return ans;

    }
};