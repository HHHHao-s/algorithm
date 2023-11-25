#include "../s.h"

class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        
        vector<int> st;
        int cur;
        for(int i=0;i<nums.size();i++){
            cur =  nums[i];
            
            while(!st.empty() && cur<st.back() && i<nums.size()){
                
                i++;
                if(i<nums.size()){
                    cur+= nums[i];
                }else{
                    break;
                }
                
            }
            if(st.empty() || cur>=st.back()){
                st.push_back(cur);
            }else{
                st.back()+=cur;
            }
            

        }
        
        return st.size();

    }
};

int main(){

    Solution s;
    vector<int> nums = {272,482,115,925,983};
    cout << s.findMaximumLength(nums);
}