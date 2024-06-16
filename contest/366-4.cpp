#include "../s.h"


class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> ks(k,0);
        int n = nums.size();
        
        vector<int> digit(32);
        int high=0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            int off=0;
            while(num >= (1<<off)){
                if((num&(1<<off))){
                    digit[off]++;
                    high = max(high,off);
                }
                off++;
            }

        }
        long long ans=0;
        for(int i=0;i<k;i++){
            long long num = 0;
            for(int j=0;j<32;j++){
                if(digit[j]>0){
                    digit[j]--;
                    num+=(1<<j);
                }                
            }
            ans = (ans + num*num)%1000000007;
        }
        return (int)ans;
    }
};

int main(){
    Solution s;

    vector<int> v = {
        1,4,8,16,3,7,15
    };

    cout<< s.maxSum(v, 3);

    return 0;
}