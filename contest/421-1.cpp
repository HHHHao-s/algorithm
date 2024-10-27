#include "../s.h"

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        long long ans= 0;
        for(int i=0;i<=nums.size();i++){
            long long l=0,g=0;

            for(int j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                if(l==0){
                    l = nums[j];
                }else{
                    l = lcm<long long>(nums[j], l);
                }
                if(g==0){
                    g = nums[j];
                }else{
                    g = gcd<long long>(nums[j], g);
                }

            }
            ans = max(ans, l*g);
            

        }

        

        return ans;

    }
};

int main(){
    vector<int> n ={1,2,3,4,5};
    Solution().maxScore(n);
}