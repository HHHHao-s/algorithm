#include "s.h"
/*
 * @lc app=leetcode.cn id=2484 lang=cpp
 *
 * [2484] 统计回文子序列数目
 */

// @lc code=start
class Solution {
public:
    int countPalindromes(string s) {
        
        vector<vector<long long>>  back(10, vector<long long>(10));
        vector<long long> back_one(10);
        int n = s.size();
        if(n<5){
            return 0;
        }
        for(int i=n;i-->2;){

            int digit = s[i]-'0';
            for(int j=0;j<10;j++){
                back[digit][j]+=back_one[j];
            }
            back_one[digit]++;

        }
        vector<long long> pre_one(10);
        vector<vector<long long>>  pre(10, vector<long long>(10));
        for(int i=0;i<2;i++){
            int digit = s[i]-'0';
            for(int j=0;j<10;j++){
                pre[digit][j]+=pre_one[j];
            }
            pre_one[digit]++;
        }
        long long ans = 0;
        for(int k=2;k<n-2;k++){
            

            int digit = s[k]-'0';
            back_one[digit]--;
            for(int j=0;j<10;j++){
                back[digit][j]-=back_one[j];
            }
            
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    ans += pre[i][j]*back[i][j];
                }
            }
            for(int j=0;j<10;j++){
                pre[digit][j]+=pre_one[j];
            }
            pre_one[digit]++;
            
        }
        return (int)(ans % 1000000007);

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.countPalindromes("103301");

}