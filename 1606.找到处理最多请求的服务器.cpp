#include "s.h"
/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        map<int, vector<int>> expire;
        set<int> free;
        vector<int> requests(k);
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        int n = arrival.size();
        for(int i=0;i<n;i++){
            int arr = arrival[i];
            int ld = load[i];
            while(!expire.empty() && expire.begin()->first<=arr){
                for(auto server: expire.begin()->second){
                    free.insert(server);

                }
                expire.erase(expire.begin()->first);
            }
            if(free.empty()){
                continue;
            }else{
                auto it = free.lower_bound(i%k);
                if(it==free.end()){
                    it = free.begin();
                }
                int index = *it;
                free.erase(index);
                expire[arr+ld].push_back(index);
                requests[index]++;

            }
        }
        int mx_request=-1;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(mx_request<requests[i]){
                mx_request=requests[i];
                ans.clear();
                ans.push_back(i);
            }else if(mx_request==requests[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

