#include "s.h"
/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */

// @lc code=start
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {

        long long l=1;
        long long r = 1000000;

        while(l<=r){
            long long mid = l+(r-l)/2;
            long long start = 0;
            long long end = mid;
            long long tmp = end*(mid+1)/2;
            long long step = mid+1;
            long long up_end =tmp+ mid*step;
            long long block = (tmp+up_end)*(mid+1)/2;
            long long sum = 4*block-4*tmp;
            if(sum>=neededApples){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return (r+1)*8;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minimumPerimeter(1);
}