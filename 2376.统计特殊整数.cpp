#include "s.h"
/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 *
 * [2376] 统计特殊整数
 */

// @lc code=start
class Solution {
private:

    

    vector<vector<int>> memo{1<<10, vector<int>(11, -1)};

    int f(int mask, int limit, int cur,vector<int>& each_digit, int is_num){
        if(cur==each_digit.size()){
            if(is_num)
                return 1;
            else
                return 0;
        }
        if(!limit && memo[mask][cur]!=-1){
            return memo[mask][cur];
        }

        int top = limit?each_digit[cur]:9;
        int ans = 0;
        if(!is_num){
            ans = f(0 ,0, cur+1, each_digit, 0);
        }
        for(int i=0;i<=top;i++){
            if((mask&(1<<i))==0 ){
                if(i!=0 || is_num){
                    ans+=f(mask|(1<<i), (i==top)&&limit, cur+1, each_digit, 1);                
                } 
            }
        }
        if(!limit && is_num){
            memo[mask][cur] = ans;
        }
        
        return ans;
    }

public:
    int countSpecialNumbers(int n) {
        
        int tmp = n;
        vector<int> each_digit;
        while(tmp){
            each_digit.push_back(tmp%10);
            tmp/=10;

        }
        reverse(each_digit.begin(), each_digit.end());
        return f(0, 1, 0, each_digit, 0);

    }
};
// @lc code=end

int main(){
    Solution s;
    cout<< s.countSpecialNumbers(420);
}