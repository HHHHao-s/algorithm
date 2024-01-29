#include "s.h"
/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {

        unordered_map<int, int> dp;
        vector<vector<int>> each_index(26);
        for(int i=0;i<ring.size();i++){
            char c = ring[i];
            each_index[c-'a'].push_back(i);
        }
        int n = ring.size();
        for(int index: each_index[key[0]-'a']){
            dp[index] = min(index, n-index);
        }
        
        for(int i=1;i<key.size();i++){
            char c = key[i];
            unordered_map<int,int> new_dp;
            for(int ki:each_index[c-'a']){
                new_dp[ki] = INT_MAX;
                for(auto [li, step]:dp){
                    int dis=INT_MAX;
                    if(ki<li){
                        dis = min(li-ki, n-li+ki);

                    }else{
                        dis = min(ki-li, n-ki+li);
                    }
                    new_dp[ki] = min(new_dp[ki], step+dis);
                }
            }
            dp = new_dp;
        }

        int ans= INT_MAX;
        for(auto [li, step]: dp){
            ans = min(ans, step);
        }
        return ans + key.size();


    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.findRotateSteps("edcba", "abcde");
}