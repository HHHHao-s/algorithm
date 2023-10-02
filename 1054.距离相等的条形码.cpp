#include "s.h"
/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        auto f= [](pair<int,int> a, pair<int,int> b){
                return a.second<b.second;
            };

        priority_queue<pair<int,int>, vector<pair<int,int>> , decltype(f)>
            p(f);

        unordered_map<int,int> m;

        for(int x: barcodes){
            m[x]++;
        }
        for(auto [x,t]:m){
            p.push({x,t});
        }
        int n = barcodes.size();
        vector<int> ret(n, -1);

        int max_time = p.top().second;
        int gap = (n+1)/max_time;

        auto [x,t] = p.top();
        p.pop();
        for(int i=0;i<gap;i++){
            int j=i;
            
            
            for(;j<n;j+=gap){
                ret[j] = x;
                if(--t==0){
                    x = p.top().first;
                    t = p.top().second;
                    p.pop();
                }
            }
        }

        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> b={
        1,1,1,2,2,2,2,1,3
    };
    printArr(s.rearrangeBarcodes(b));

    return 0;
}