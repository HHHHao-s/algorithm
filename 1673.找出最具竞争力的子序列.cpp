#include "s.h"
/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> st;

        int n = nums.size();
        int erase = n-k;
        vector<int> ret;
        for(int i=0;i<n;i++){
            int num = nums[i];
            while(!st.empty() && erase>0 && num<st.back()){
                erase--;
                st.pop_back();

            }

            st.push_back(num);
            if(erase==0){
                
                while(!st.empty()){
                    ret.push_back(st.front());
                    st.pop_front();
                }
                for(int j = i+1;j<n;j++){
                    ret.push_back(nums[j]);
                }
                return ret;
            }
        }
        for(int i=0;i<k;i++){
            ret.push_back(st.front());
            st.pop_front();
        }
        return ret;


    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> nums = {
       3,5,2,6
    };

    printArr(s.mostCompetitive(nums, 2));


    return 0;
}