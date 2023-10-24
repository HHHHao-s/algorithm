#include "s.h"
/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(const vector<int>& arr) {

        int n = arr.size();
        if(n==1){
            return arr[0];
        }
        deque<pair<int,int>> q;
        q.push_back({-1,-1});
        vector<long long > pre(n),back(n);
        for(int i=0;i<n;i++){
            int x = arr[i];
            // 这里要使用>=，因为如果两边都是>，会有少，两边都是>=，会有重复，
            // 如果一边>,一边>=,那么，每一个连续的最小值都只会计算一半的子数组，从而不产生重复
            while(!q.empty()&& q.back().first>=x){
                q.pop_back();
                
            }
            pre[i] = q.back().second;
            q.push_back({x,i});
            
        }
        q=deque<pair<int,int>>();
        q.push_back({-1,n});
        for(int i=n;i-->0;){
            int x = arr[i];
            while(!q.empty() && q.back().first>x){
                q.pop_back();
            }
            back[i] = q.back().second;
            q.push_back({x,i});

        }
        long long ans=0;
        for(long long i=0;i<n;i++){

            ans = (ans+(((i-pre[i])*(back[i]-i))%1000000007*arr[i])%1000000007)%1000000007;
        }
        return (int)ans;
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.sumSubarrayMins({3,3,3,3});

}