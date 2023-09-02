#include "s.h"
/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> in(n);
        vector<vector<int>> m(n, vector<int>(n));


        auto f = [](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(f)> pq(f);

        for(auto road: roads){
            int a = road[0];
            int b = road[1];
            in[a]++;
            in[b]++;
            m[a][b] = 1;
            m[b][a] = 1;
        }

        for(int i=0;i<n;i++){
            pq.push({in[i],i});
        }

        

        auto [a1,i1] = pq.top();
        pq.pop();
        auto [a2,i2] = pq.top();
        pq.pop();

        int ans=m[i1][i2]==1?a1+a2-1:a1+a2;    

        if(a1==a2 && m[i1][i2]==1){// 有机会更小
            vector<int> same = {i1,i2};
            ans= a1+a2-1;
            while(!pq.empty()){
                auto [a3,i3] = pq.top();
                pq.pop();
                if(a3==a2){
                    same.push_back(i3);
                }else{
                    break;
                }
            }
            int sz = same.size();
            for(int i=0;i<sz; i++){
                int flag = 0;
                for(int j=i+1;j<sz;j++){
                    if(m[same[i]][same[j]]==0){
                        ans = a2+a1;
                        flag = 1;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
            
        }else if(a1>a2 && m[i1][i2]==1){
            while(!pq.empty()){
                int c=0;
                auto [a3,i3] = pq.top();
                pq.pop();

                if(a3==a2){
                    ans = max(ans,m[i1][i3]==1?a1+a3-1:a1+a3);
                    continue;             
                }
                break;               
            }
        }else{
            ans = a1+a2;
        }


        

        return ans;

    }
};
// @lc code=end

int main(){


    Solution s;

    vector<vector<int>> roads={
        {2,3},
        {0,3},
        {0,4},
        {4,1},
    };

    vector<vector<int>> roads2={
        {0,1},
        {0,2},
        {0,5},
        {1,4},
        {1,2},
        {2,5},
        {3,5}
    };

    vector<vector<int>> roads3={
        {0,1},{0,3},{1,2},{1,3},{2,3},{2,4}
    };

    cout <<s.maximalNetworkRank(5,roads3);

    return 0;
}