#include "s.h"
/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int max_w = verticalCuts[0], max_h = horizontalCuts[0];
        int pos_w = 0, pos_h = 0;
        for(int i = 1; i < verticalCuts.size(); i++){
            if(verticalCuts[i] - verticalCuts[i-1] > max_w){
                max_w = verticalCuts[i] - verticalCuts[i-1];
                pos_w = i;
            }
        }
        for(int i = 1; i < horizontalCuts.size(); i++){
            if(horizontalCuts[i] - horizontalCuts[i-1] > max_h){
                max_h = horizontalCuts[i] - horizontalCuts[i-1];
                pos_h = i;
            }
        }
        if(w - verticalCuts[verticalCuts.size()-1] > max_w){
            max_w = w - verticalCuts[verticalCuts.size()-1];
            pos_w = verticalCuts.size();
        }
        if(h - horizontalCuts[horizontalCuts.size()-1] > max_h){
            max_h = h - horizontalCuts[horizontalCuts.size()-1];
            pos_h = horizontalCuts.size();
        }
        return (long long)max_w * max_h % 1000000007;

    }
};
// @lc code=end

