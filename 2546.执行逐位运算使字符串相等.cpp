#include "s.h"
/*
 * @lc app=leetcode.cn id=2546 lang=cpp
 *
 * [2546] 执行逐位运算使字符串相等
 */

// @lc code=start
class Solution {
// private:
//     string doit(string& s,int i,int j){
//         string ret = s;
//         char ci = s[i];
//         char cj = s[j];
//         if(ci==1&&cj==1){
//             ret[i]=1;
//             ret[j]=0;
//         }else if((ci==1 && cj==0) || (ci==0 && cj==1)){
//             ret[i]=1;
//             ret[j]=1;
//         }else{
//             // meaningless
//             ret[i] = 0;
//             ret[j]=0;
//         }
//         return ret;
//     }

public:
    bool makeStringsEqual(string s, string target) {
        int diff=0;
        int ones = 0;
        int zeros = 0;
        bool have_one = false;
        bool have_zero = false;


        for(int i=0;i<target.size();i++){
            if(s[i]!=target[i]){
                diff++;
                if(s[i]=='0'){
                    // 0->1
                    zeros++;
                }else{
                    // 1->0
                    ones++;
                }
            }else{
                if(s[i]=='0'){
                    have_zero=true;
                }else{
                    have_one=true;
                }
            }
            
        }
        if(diff==0){
            return true;
        }else if(zeros==0 && ones>0 && !have_one){
            return false;
        }else if(ones==0 && zeros>0 && !have_one){
            return false;
        }else{
            return true;
        }



    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.makeStringsEqual("100101000101110001",
"000101000000110001");

    return 0;
}