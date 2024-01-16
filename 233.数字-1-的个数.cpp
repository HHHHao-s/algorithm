#include "s.h"
/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        if(n==0){
            return 0;
        }
        vector<vector<int>> memo(10, vector<int>(10,-1));
        int tmp = n;

        string s = to_string(n);

        // 前导0对答案无影响，忽略
        function<int(int ,int ,int )> f = [&](int i, int j, int is_limit){

            if(i==s.size() ){
                return j;
            }
            if(!is_limit && memo[i][j]!=-1){
                return memo[i][j];
            }
            int res = 0;
            

            
            int up = is_limit?(s[i]-'0'):9;
            for(int k=0;k<=up;k++){
                res += f(i+1, j+(k==1), (k==up)&&is_limit);
            }
            if( !is_limit){
                memo[i][j] = res;
            }
            return res;

        };

        return f(0, 0, 1);

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.countDigitOne(100);
}