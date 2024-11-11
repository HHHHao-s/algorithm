#include "s.h"
/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] 切棍子的最小成本
 */

// @lc code=start
class Solution {
private:
    

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        unordered_map<int ,unordered_map<int,int> > f;

        auto dfs=[&](auto &&dfs, int l ,int r){

            if(l<r && f[l].count(r)){
                return f[l][r];
            }
            if(l>=r){
                return 0;
            }
            int ans= INT_MAX ;
            auto it = upper_bound(cuts.begin(), cuts.end(), l);
            for(;it!=cuts.end() && *it<r; it++){

                ans = min(ans, dfs(dfs, l, *it)+dfs(dfs, *it, r)+r-l);

            }
            if(ans==INT_MAX){
                ans = 0;
            }
            cout << l << ' ' << r << ' ' << ans << endl;

            f[l][r] = ans;
            return ans;

        };

        return dfs(dfs, 0, n);

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> cuts = {1,3,4,5};
    cout << s.minCost(9, cuts);
}