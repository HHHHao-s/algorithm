#include "s.h"
/*
 * @lc app=leetcode.cn id=1851 lang=cpp
 *
 * [1851] 包含每个查询的最小区间
 */

// @lc code=start
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        map<int,vector<int>> rl;
        map<int, int> lenCnt;

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> qu;
        for(int q:queries){
            qu.push_back({q, qu.size()});
        }
        sort(qu.begin(), qu.end());
        vector<int> ans(qu.size());
        int p=0;
        for(auto [q, index]: qu){
            while(p<intervals.size() && intervals[p][0]<=q){
                rl[intervals[p][1]].push_back(intervals[p][0]);// r->ls
                lenCnt[intervals[p][1]-intervals[p][0]+1]++;
                p++;
            }
            while(!rl.empty() && rl.begin()->first<q){
                int r = rl.begin()->first;
                for(int l:rl.begin()->second){
                    lenCnt[r-l+1]--;
                    if(lenCnt[r-l+1]==0){
                        lenCnt.erase(r-l+1);
                    }
                }
                rl.erase(r);
            }


            ans[index] = lenCnt.empty()?-1:lenCnt.begin()->first;

        }

        return ans;



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> intervals={
        {2,3},
        {2,5},
        {1,8},
        {20,25}
    };
    vector<int> queries={
        2,19,5,22
    };
    printArr(s.minInterval(intervals, queries));
}