#include "../s.h"

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        
        long long m= values.size();
        long long n = values[0].size();
        struct status{
            long long value, index, cur;
        };
        auto f = [&](const status&a,const status&b){
            return a.value<b.value;
        };
        
        priority_queue<status, vector<status>, decltype(f)> pq(f);
        for(int i=0;i<m;i++){

            pq.push((status){values[i][0],i, 0});

        }
        long long ans = 0;
        for(long long i=m*n;i>=1;i--){
            auto [value, index, cur] = pq.top();
            pq.pop();
            ans += i*value;
            if(cur+1<n){
                pq.push((status){values[index][cur+1], index, cur+1});
            }
            

        }

        return ans;
    }
};

