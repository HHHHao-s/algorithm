#include "s.h"
/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(),satisfaction.end(),std::greater<int>());

        int cur=0;
        vector<int> need;
        for(int i=0;i<satisfaction.size();i++){
            cur+=satisfaction[i];
            if(cur<=0){
                break;
            }else{
                need.push_back(satisfaction[i]);
            }


        }
        int ans = 0;
        int sz = need.size();
        for(auto x: need){
            ans += x*sz;
            sz--;
        }
        return ans;

    }
};
// @lc code=end

