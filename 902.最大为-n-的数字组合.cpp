#include "s.h"
/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
    

public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int sz = digits.size();
        int tmp=n;
        int p = 0;
        int high = n;
        while(tmp>0){
            p++;
            high = tmp;
            tmp/=10;
        }
        int ans = 0;
        int init=1;
        
        for(int i=1;i<=p-1;i++){
            init*=sz;
            ans += init;
            
        }
        string ns = to_string(n);

        int pos = 0;
        vector<int> dig;
        for(int j=sz;j-->0;){
            dig.push_back(digits[j][0]-'0');
        }
        
        while(pos<p){
            int cur = ns[pos]-'0';
            auto it= lower_bound(dig.begin(),dig.end(), cur, std::greater<int>());
            if(it!=dig.end()){
                if(*it==cur){
                    ans += (dig.end()-it -1)*pow(sz,p-pos-1);
                    if(pos==p-1){
                        ans++;
                    }
                    
                    
                }else{
                    ans += (dig.end()-it)*pow(sz, p-pos-1);
                    break;
                }
            }else{
                break;
            }
            pos++;
            
            
        }

        return ans;
    }   
};
// @lc code=end

int main(){
    Solution s ;
    vector<string> digits={
        "1","4","9"
    };
    cout << s.atMostNGivenDigitSet(digits, 4199);

}