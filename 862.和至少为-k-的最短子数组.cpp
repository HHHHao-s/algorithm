#include "s.h"
/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        long long cur = 0;
        int n = nums.size();
        deque<pair<long long,int> > q;
        q.push_back({0, 0});
        
        int res = n+1;
        for(int i=1;i<=n;i++){
            cur+= nums[i-1];
            // 先对队头的元素匹配最短
            // 可以证明如果匹配成功，那么此时匹配的长度最短
            // 因此可以直接弹出
            while(!q.empty() && cur - q.front().first>=k){
                res = min(res, i-q.front().second);
                q.pop_front();
            }
            // 然后将此队列进行修剪，队尾元素越小越有利于寻找>=k的子数组
            while(!q.empty() && cur<=q.back().first){
                q.pop_back();
            }
            q.push_back({cur ,i});

        }

        return res == n+1?-1:res;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1};
    cout<<s.shortestSubarray(nums, 1);
}