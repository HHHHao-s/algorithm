#include "s.h"
#include "s.h"

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;

        for(int i=0;i<n;i++){
            int cur = 0;
            unordered_set<int> vis;
            for(int j=i;j>=0;j--){
                
                if(!vis.count(nums[j])){
                    cur++;
                    vis.insert(nums[j]);
                    ans = (ans + cur*cur)%(1000000007);
                }else{
                    ans = (ans + cur*cur)%(1000000007);
                }
                
            }
        }
        return ans;
    }

};

int main(){


    
}
