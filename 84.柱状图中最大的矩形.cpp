#include "s.h"
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
private:
    int myLargestRectangleArea(vector<int>& heights){
        stack<int> st;
        int max_size = 0;
        int n = heights.size();
        st.push(0);
        for(int i=0;i<n;i++){
            
            int x = heights[i];
            int size=x;
            while(x<=st.top()){
                size+=x;
                st.pop(); 
            }
            st.push(x);
            max_size  = max(max_size, size);
        }
        
        return max_size;
    }

public:
    
    int largestRectangleArea(vector<int>& heights) {
        int l = myLargestRectangleArea(heights);
        reverse(heights.begin(), heights.end());
        int r = myLargestRectangleArea(heights);
        
        return max(l,r);
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> h = {1,1};

    cout << s.largestRectangleArea(h);


    return 0;
}