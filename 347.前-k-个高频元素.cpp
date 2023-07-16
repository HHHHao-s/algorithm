#include "s.h"
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int,int> map; // num to occurance
        int n = nums.size();
        
        for(auto it:nums){
            map[it]++;
        }

        auto cmp = [](pair<int,int> p1, pair<int,int> p2){
            return p1.second>p2.second; // 最小堆
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> p(cmp);

        for(auto it:map){
            if(p.size()<k){
                p.emplace(it);
            }else{
                if(p.top().second < it.second){
                    p.pop();
                    p.emplace(it);
                }
            }
        }
        vector<int> ret;
        while(!p.empty()){
            ret.push_back(p.top().first);
            p.pop();
        }
        return ret;
    }
};
// @lc code=end

int main(){

    Solution s;

    printArr(s.topKFrequent({1,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5},3));


    return 0;
}

