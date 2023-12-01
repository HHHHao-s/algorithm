#include "s.h"
/*
 * @lc app=leetcode.cn id=1439 lang=cpp
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int sz=0;
        auto f=[&](const pair<string,int>&p1, const pair<string,int>&p2){
            return p1.second>p2.second;

        };
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(f)> pq(f);
        int sum=0;
        string init;
        for(int i=0;i<m;i++){
            sum+=mat[i][0];
            init.push_back(0);
        }

        pq.emplace(init, sum);
        int cur=0;
        unordered_set<string> vis;
        while(1){
            auto [min_vec, sum] = move(pq.top());
            pq.pop();
            cur++;
            if(cur==k){
                return sum;
            }
            for(int i=0;i<m;i++){
                if(min_vec[i]+1<n){
                    int diff = mat[i][min_vec[i]+1]-mat[i][min_vec[i]];
                    min_vec[i]++;
                    if(vis.count(min_vec)==0){
                        pq.emplace(min_vec, sum+diff);
                        vis.insert(min_vec);
                    }
                    
                    min_vec[i]--;
                }
                

            }
        }
        return 0;
        
    }   
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>> mat={
        {1,10,10},
        {1,4,5},
        {2,3,6}
    };
    cout << s.kthSmallest(mat, 7);
}