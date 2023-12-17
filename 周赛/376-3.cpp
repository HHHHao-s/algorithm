#include "../s.h"
#include "string.h"

class Solution {
private:
    
    bool check(int num){
        char buf[64];
        int i=0;
        while(num){
            buf[i] = num%10;
            num/=10;
            i++;
        }
        buf[i] = 0;
        int n = i;
        
        for(int i=0;i<n/2;i++){
            if(buf[i]!=buf[n-i-1]){
                return false;
            }
        }
        return true;
    }

public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int mid = nums[nums.size()/2];
        long long  ans=0;
        for(int i=mid;;i++){
            if(check(i)){
                for(int x:nums){
                    ans += abs(x-i);
                
                }
                break;
            }
        }
        long long  tmp=0;
        for(int i=mid;;i--){
            if(check(i)){
                for(int x:nums){
                    tmp += abs(x-i);
                }
                break;
            }
        }
        return min(tmp, ans);


        
        

    }
};

int main(){

    Solution s;
    vector<int > nums={
        10,12,13,14,15  
    };
    cout << s.minimumCost(nums);
}