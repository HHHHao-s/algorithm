#include "s.h"
/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        struct info{
            double qw;
            int q;
            int w;
            int index;
        };

        vector<info> infos;
        int n = quality.size();
        for(int i=0;i<n;i++){
            infos.push_back({(double)wage[i]/quality[i], quality[i], wage[i], i});
        }

        sort(infos.begin(), infos.end(), [](const info&a, const info&b){
            return a.qw<b.qw;

        });

        priority_queue<int> pq;
        int cur = 0;
        double ans = INT32_MAX;
        for(int i=0;i<k;i++){
            pq.push(infos[i].q);
            cur+=infos[i].q;
            
        }
        ans = infos[k-1].qw * cur;
        for(int i=k;i<n;i++){
            cur -= pq.top();
            pq.pop();
            pq.push(infos[i].q);
            cur+=infos[i].q;
            ans = min(ans, cur*infos[i].qw);

        }
        return ans;


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> qu={10,20,5};
    vector<int> wage={70,50,30};
    cout<<s.mincostToHireWorkers(qu,wage, 2);
}