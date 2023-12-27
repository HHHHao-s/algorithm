#include "s.h"
/*
 * @lc app=leetcode.cn id=1889 lang=cpp
 *
 * [1889] 装包裹的最小浪费空间
 */

// @lc code=start
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {

        sort(packages.begin(), packages.end());
        vector<long long> sum(100001, -1);
        const long long MOD = 1000000007;
        long long index=0;
        long long t = packages[index];
        for(long long i=1;i<=100000;i++){
            
            
            if(t>i){
                continue;
            }
            
            sum[i]=(sum[i-1]+index+1);
            while(index+1<packages.size()&&packages[index+1]<=i){
                index++;
                t = packages[index];
            }

            
            
        }
        long long ans = LONG_LONG_MAX;

        for(auto &box: boxes){
            sort(box.begin(), box.end());
            long long put=0;
            long long whole = 0;
            for(long long bx:box){
                int pos = upper_bound(packages.begin(), packages.end(), bx)-packages.begin();
                if(pos==0){
                    continue;
                }
                pos--;

                
                if(put>0){
                    long long last = packages[put-1];
                    long long part = sum[last];
                    whole = (whole+(sum[bx]-(bx-last)*(put)-part));
                    // whole = (((whole+sum[bx])%MOD-(bx-last)*(put))%MOD-part)%MOD;
                }else{
                    whole = (whole+sum[bx]);
                }
                put = pos+1;



            }
            if(put==packages.size()){

                ans = min(ans, whole);
            }
        }
        if(ans == LONG_LONG_MAX){
            return -1;
        }else{
            ans %= MOD;
            if(ans<0){
                ans+=MOD;
            }
            return ans;
        }
        return -1;



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> ps = {3,5,8,10,11,12};
    vector<vector<int>> boxes={
        {12},
        {11,9},
        {10,5,14}
    };
    cout << s.minWastedSpace(ps, boxes);
}