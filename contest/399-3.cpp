#include "../s.h"

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        long long ret=0;
        vector<int> nums3;
        for(int num: nums1){
            if(num%k == 0){
                nums3.push_back(num/k);
            }    
        }
        unordered_map<int,int> ct;
        for(int num: nums2){
            ct[num]++;
        }
        for(int num : nums3){
            for( int i=1;i*i<=num;i++){
                if(num%i==0){
                    
                    ret += ct[i];
                    if(i != num/i)
                        ret += ct[num/i];
                }
            }
        }
        return ret;

    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,4};
    vector<int> nums3 = {1,3,4};
    cout << s.numberOfPairs(nums ,nums3, 1);
}