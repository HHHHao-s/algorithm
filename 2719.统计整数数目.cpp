#include "s.h"
/*
 * @lc app=leetcode.cn id=2719 lang=cpp
 *
 * [2719] 统计整数数目
 */

// @lc code=start
class Solution {
private:
    int n1,n2;
    int min_num,max_num;
    string num1, num2;
    const long long MOD = 1e9+7;

    long long dfs(string &s, int is_limit, int is_num, int sum,int i, vector<vector<long long>>& memo,int min_sum, int max_sum){

        if (i == s.size() )
            return is_num&& sum>=min_sum && sum<=max_sum; // is_num 为 true 表示得到了一个合法数字
        if (!is_limit && is_num && sum<=max_sum && memo[i][sum] != -1)
            return memo[i][sum];
        long long res = 0;
        if (!is_num) // 可以跳过当前数位
            res = dfs(s, 0, 1, sum, i+1, memo,min_sum,max_sum);
        int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
        for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
            
            res = (res+dfs(s, d==up&&is_limit,1,sum+d, i+1, memo, min_sum, max_sum ))%MOD;
            
        if (!is_limit && is_num)
            memo[i][sum] = res;
        return res;


        
    }

    void sub(string &num){
        int carry=-1;
        for(int j=num.size()-1;j>=0;j--){
            if(carry){
                if(num[j]=='0'){
                    num[j]='9';
                    carry=-1;
                }else{
                    num[j]-=1;
                    return ;
                }
                
            }else{
                return;
            }
        }
        if(num[0]=='0' && num.size()>1){
            num = num.substr(1);
        }


    }

    

public:
    int count(string _num1, string _num2, int _min_sum, int _max_sum) {
        vector<vector<long long>> memo(23, vector<long long>(401,-1));
        long long res2 = dfs(_num2, 1, 0, 0, 0,memo, _min_sum,_max_sum );
        sub(_num1);
        memo = vector<vector<long long>>(23, vector<long long>(401,-1));
        long long res1 = dfs(_num1,1, 0, 0, 0,memo, _min_sum,_max_sum  );
        res2-=res1;
        if(res2<0){
            res2+=MOD;
        }
        return res2;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout<< s.count("4179205230", "7748704426", 8, 46);
}