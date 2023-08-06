#include "s.h"
/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        int a1=0,a2=0;
        int b1=m.begin()->first,b2=m.begin()->second*b1;
        for(auto it=++m.begin();it!=m.end();it++ ){
            if(it->first==b1+1){ // 递增

                int tmp = it->first*it->second+a2;
                a2 = max(a2,b2);
                b2 = tmp;
                b1 = it->first;
            }else{
                int tmp = max(it->first*it->second+a2, it->first*it->second+b2);
                a2 = max(a2,b2);
                b2 = tmp;
                b1 = it->first;
            }
        }   
        return max(a2,b2);

    }
};
// @lc code=end

int main(){

    vector<int> arr = {2,2,3,3,3,4,6};
    Solution s;
    cout << s.deleteAndEarn(arr);

    return 0;
}