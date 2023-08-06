#include "s.h"
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
private:

public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        stack<int> st;

        vector<int> left(n),right(n);

        for(int i=0;i<n;i++){
            int x = heights[i];
            while(!st.empty()&&x<=heights[st.top()]){
                st.pop();
            }
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }


        st = stack<int>();

        for(int i=n;i-->0;){
            int x = heights[i];
            while(!st.empty()&&x<=heights[st.top()]){
                st.pop();
            }
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){

            int h = heights[i];
            ans = max(ans, (right[i]-left[i]-1)*h);

        }
        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> h = {1,1,1,1,1,1,1};

    cout << s.largestRectangleArea(h);


    return 0;
}