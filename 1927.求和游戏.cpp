#include "s.h"
/*
 * @lc app=leetcode.cn id=1927 lang=cpp
 *
 * [1927] 求和游戏
 */

// @lc code=start
class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();
        int left=0;
        int right=0;
        int leftq=0;
        int rightq=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                leftq++;
            }else{
                left+=num[i]-'0';
            }
            if(num[n-i-1]=='?'){
                rightq++;
            }else{
                right+=num[n-i-1]-'0';
            }
        }

        if(left>right){
            left-=right;
            right=0;
        }
        else{
            swap(left,right);
            swap(leftq,rightq);
            left-=right;
            right=0;

        }
        if(leftq==rightq){
            if(left!=0){
                // impossible to equal
                return true;
            }else{
                return false;
            }
            
        }
        else if(rightq>leftq){
            rightq-=leftq;
            if(left!=0){
                if(rightq%2==0){
                    return left!=(rightq/2)*9;
                }else{
                    return true;
                }
            }else{
                return true;
            }
        }else{
            return true;
        }
        return false;



    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.sumGame("?3295???");
}