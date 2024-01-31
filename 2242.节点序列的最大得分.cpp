#include "s.h"
/*
 * @lc app=leetcode.cn id=2242 lang=cpp
 *
 * [2242] 节点序列的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
        int n = scores.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(-scores[y], y);
            g[y].emplace_back(-scores[x], x);
        }
        for (auto &vs : g)
            if (vs.size() > 3) {
                nth_element(vs.begin(), vs.begin() + 3, vs.end());
                vs.resize(3);
            }

        int ans = -1;
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            for (auto &[score_a, a] : g[x])
                for (auto &[score_b, b] : g[y])
                    if (a != y && b != x && a != b)
                        ans = max(ans, -score_a + scores[x] + scores[y] - score_b);
        }
        return ans;
    }
};

// @lc code=end

int main(){
    Solution s;
    vector<int> scores={5,2,9,8,4};
    vector<vector<int>> edges={
        {0,1},
        {1,2},
        {2,3},
        {0,2},
        {1,3},
        {2,4}
    };
    cout<<s.maximumScore(scores, edges); 
}