#include "s.h"
/*
 * @lc app=leetcode.cn id=1739 lang=cpp
 *
 * [1739] 放置盒子
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(int n) {

        long long cur=1;
        long long floor = 2;
        long long down = 3;

        long long next_cur = 4;

        while( next_cur<n){
            cur = next_cur;
            floor++;

            down = down+floor;
            next_cur = cur+down;
        }
        if(next_cur==n){
            return down;
        }else{
            down-=floor;
            // floor--;
            int have = n-cur;
            int put=0;
            for(int i=1;have>0;i++){
                have-=i;
                put++;
            }
            return down + put;
        }
        return 0;


    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minimumBoxes(126) << endl;
    cout << s.minimumBoxes(10)<< endl;
    cout << s.minimumBoxes(9)<< endl;
    cout << s.minimumBoxes(6)<< endl;
    cout << s.minimumBoxes(7)<< endl;
    cout << s.minimumBoxes(8)<< endl;
}