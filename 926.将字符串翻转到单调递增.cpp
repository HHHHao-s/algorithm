#include "s.h"
/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n =s.size();
        vector<pair<int,int>> pre(n+1),back(n+1);
        int p0=0,p1=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){
                p0++;
                
            }else{
                p1++;
                
            }
            pre[i].first=p0;
            pre[i].second=p1;
        }
        int b0=0,b1=0;
        for(int i=n;i-->0;){
            if(s[i]=='0'){
                b0++;
                
            }else{
                b1++;
                
            }
            back[i].first=b0;
            back[i].second=b1;
        }
        int ans = min({back[0].first, back[0].second}); // 全部换成0或1
        for(int i=1;i<=n;i++){
            ans = min({ans, pre[i].second+back[i].first}); // 前面1换成0，后面0换成1
        }
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;

    // cout << s.minFlipsMonoIncr("00110");
    cout << s.minFlipsMonoIncr("00011000");

    return 0;
}