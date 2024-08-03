#include "s.h"
/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int>& p1, vector<int>& p2) {return p1[1] != p2[1]? p1[1] < p2[1]: p1[0] < p2[0];});
        int prepre = intervals[0][1] - 1, pre = intervals[0][1], ans = 2;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] == pre) {
                // 前一个区间与当前区间相交一个点，要把当前区间的右端点加进来
                prepre = pre;
                pre = intervals[i][1];
                ans++;
            }else if(intervals[i][0] > pre) {
                // 前一个区间与当前区间不相交，把当前区间的最后两个点加进来
                ans += 2;
                prepre = intervals[i][1] - 1;
                pre = intervals[i][1];
            }else {
                if(intervals[i][0] > prepre) {
                    if(pre == intervals[i][1]) prepre = intervals[i][1] - 1;
                    else prepre = pre;
                    pre = intervals[i][1];
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> in{{1,3},{3,7},{8,9}};
    cout << s.intersectionSizeTwo(in);
}