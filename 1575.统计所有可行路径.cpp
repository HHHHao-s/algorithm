#include "s.h"
/*
 * @lc app=leetcode.cn id=1575 lang=cpp
 *
 * [1575] 统计所有可行路径
 */

// @lc code=start
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fue) {
        int n = locations.size();

        vector<vector<long long>> memo(n, vector<long long>(fue+1, -1));
        const long long MOD=1e9+7;
        function<long long(int  ,int)> f = [&](int fuel, int index){
            if(memo[index][fuel]!=-1){
                return memo[index][fuel];
            }
            if(fuel==0 ){
                return index==start?1ll:0ll;
            }
            long long ans=index==start?1:0;
            for(int i=0;i<n;i++){
                if(i!=index && fuel>=abs(locations[i]-locations[index])){
                    ans= (ans + f(fuel-abs(locations[i]-locations[index]), i))%MOD;
                }
            }
            
            memo[index][fuel] = ans;
            return ans;

        };

        long long ret = f(fue, finish)%MOD;
        if(ret<0){
            ret+=MOD;

        }
        return ret;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> locations = {2,3,6,8,4};
    cout<< s.countRoutes(locations, 1,3,5);
}