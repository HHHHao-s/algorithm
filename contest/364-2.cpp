#include "../s.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        struct Info{
            int height;
            int index;
            long long sum;
        };

        vector<Info> q;// 单调队列
        vector<long long> dp(n,0);
       
        for(int i=0;i<n;i++){
            int height = maxHeights[i];
            while(!q.empty()&&q.back().height>=height){
                q.pop_back();

            }
            long long sum=0;
            if(q.empty()){
                sum  = ((long long)height)*(i+1);
                q.push_back({height, i,sum });
            }else{
                
                Info pre = q.back();
                sum = ((long long)height)*(i-pre.index)+pre.sum;
                q.push_back({height, i, sum});
            }
            
            dp[i]+=sum;
        }

        q.clear();
        for(int i=n;i-->0;i){
            int height = maxHeights[i];
            while(!q.empty()&&q.back().height>=height){
                q.pop_back();
            }
            long long sum=0;
            if(q.empty()){
                sum=((long long)height)*(n-i);
                q.push_back({height, i, sum});
            }else{
                Info pre = q.back();
                sum=((long long)height)*(pre.index-i)+pre.sum;
                q.push_back({height, i, sum});
            }
            dp[i]+=sum-height;
        }

        long long ans = *max_element(dp.begin(), dp.end());

        return ans;
    }
};

int main(){

    Solution s;
    vector<int> h={
        1000000000,1000000000,1000000000
    };

    cout << s.maximumSumOfHeights(h);


    return 0;
}