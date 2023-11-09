#include "s.h"
/*
 * @lc app=leetcode.cn id=1416 lang=cpp
 *
 * [1416] 恢复数组
 */

// @lc code=start
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n+1,1);
        // int kn = 0,tmpk=k;
        // while(tmpk){
        //     tmpk/=10;
        //     kn++;
        // }
        long long mo = 1000000007;
        for(int i=0;i<n;i++){
            long long cur = s[i]-'0';
            int j = i;
            long long tmp=0;
            while(cur<=k){
                if(cur>=1){
                    tmp = (tmp+dp[j])%mo;
                }
                
                long long carry= 10;
                while (cur/carry>0)
                {
                    carry*=10;
                }  
                j--;              
                while(j>=0 && s[j]=='0' && carry<mo){
                    carry*=10;
                    j--;
                }
                if(j>=0 && carry<mo){
                    cur = carry*(s[j]-'0')+cur;
                }else{
                    break;
                }
                
            }
            dp[i+1] = tmp;
        }
        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.numberOfArrays("1317", 2000);

}