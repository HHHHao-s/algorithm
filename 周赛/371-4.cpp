#include "../s.h"

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {

        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ret=0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            int tmp = 0;
            int l = upper_bound(nums.begin(), nums.begin()+i, num/2)-nums.begin();
            int r = i;
    
            for(int j=19;j>=0;j--){
                if(num&(1<<j)){
                    int pos = upper_bound(nums.begin()+l, nums.begin()+r, 1<<j)-nums.begin()-1;
                    if(pos>=l){
                        tmp|=1<<j;
                        r = pos+1;
                    }
                }else{
                    int pos = upper_bound(nums.begin()+l, nums.begin()+r, 1<<j)-nums.begin();
                    if(pos<r){
                        tmp|=1<<j;
                        r = pos;
                    }
                }
            }
            ret = max(ret, tmp);
        }

        return ret;
        
    }
};

int main(){

    Solution s;
    vector<int> nums = {25,30};
    cout << s.maximumStrongPairXor(nums);
    return 0;

}