#include "s.h"
/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {

private:
    struct RestaurantCompare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[1] != b[1]) {
                return a[1] > b[1];
            } else {
                return a[0] > b[0];
            }
        }
    };

    set<vector<int>, RestaurantCompare> ans_set;

public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
       for(auto &r: restaurants){
        if((!veganFriendly | r[2]) && r[3]<= maxPrice && r[4]<=maxDistance){
            ans_set.insert(r);
        }
       }
       vector<int> ret;
       for(auto ans:ans_set){
        ret.push_back(ans[0]);
       }
       return ret;
    }
};
// @lc code=end

