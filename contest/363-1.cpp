#include "../s.h"

class Solution {
private:
    vector<int> pos;

    void hs(int cur, int begin, int one_num, int k, int bit_range, int n){
        if(cur>=n || begin>bit_range){
            return ;
        }

        if(one_num==k){
            pos.push_back(cur);
            return ;
        }
        else if(one_num<k){
            hs(cur|(1<<begin), begin+1, one_num+1, k, bit_range, n);
        }
        hs(cur, begin+1, one_num, k, bit_range, n);        
    }

public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0){
            return nums[0];
        }
        if(n==1){
            return 0;
        }
        
        int bit_range = (int)log2(n-1)+1;
        
        hs(0, 0, 0, k, bit_range, n);

        unsigned long long cnt=0;

        for(int i: pos){
            cnt+=nums[i];
        }

        return cnt;
          
    }
};

int main(){

    Solution s;

    vector<int> nums={
        5,10,1,5,2
    };
    vector<int> nums2={
        4,3,2,1
    };
    vector<int> nums3={
        1, 1, 1, 1
    };

    cout <<s.sumIndicesWithKSetBits(nums2, 2);


    return 0;
}