#include "s.h"

/*
 * @lc app=leetcode.cn id=2827 lang=cpp
 *
 * [2827] 范围中美丽整数的数目
 */

// @lc code=start
class Solution {
public:
    int k ;
    vector<int> s;
    vector<vector<vector<int>>> memo;

    int f(int i, int n, int md, int is_limit, int lead_zero){
        

        if(i==s.size()){
            if(lead_zero){
                return 0;
            }else if(md==0 && n==s.size()){
                
                return 1;
            }
            return 0;
        }
        if(!lead_zero && !is_limit && memo[i][n][md] != -1){
            return memo[i][n][md];
        }
        int res = 0;
        int up = is_limit ?s[i] :9;
        for(int d=0;d<=up;d++){
            if(d==0 && lead_zero){
                res += f(i+1, n,md, 0, 1);
                continue;
            }
            if(d%2==0){
                res += f(i+1, n+1, (md * 10 +d)%k, (d==up)&&is_limit,0);
            }else if(d%2==1){
                res += f(i+1, n-1, (md*10 + d)%k, (d==up)&&is_limit,0);
            }
        }
        if(!is_limit && !lead_zero){
            memo[i][n][md] = res;
        }
        return res;

    }

    int f2(int num){
        s.clear();
        memo.clear();
        int l = num;
        while(l){
            s.push_back(l%10);
            l/=10;
        }
        reverse(s.begin(), s.end());
        memo.assign(s.size()+1 , vector<vector<int>>(2*s.size()+1, vector<int>(k+1, -1)));
        return f(0, s.size(), 0, 1, 1);
    }

    int numberOfBeautifulIntegers(int low, int high, int k_) {
        
        k = k_;
        if(low==1){
            return f2(high);
        }
        return f2(high) - f2(low-1);

       

    }
};
// @lc code=end

int main(){
    Solution s;
    cout<< s.numberOfBeautifulIntegers(36, 60, 3);
}