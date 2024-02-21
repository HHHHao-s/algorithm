#include "s.h"
/*
 * @lc app=leetcode.cn id=1937 lang=cpp
 *
 * [1937] 扣分后的最大得分
 */

// @lc code=start
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int n = points[0].size(), m=points.size();
        if(m==1){
            return (long long)*max_element(points[0].begin(), points[0].end());
        }
        vector<long long> diff1(n), diff2(n);
        for(int i=0;i<n;i++){
            diff1[i] = points[0][i]+i;
            diff2[i] = points[0][i]-i;
        }
        long long ans =0 ;
        for(int i=1;i<m;i++){
            map<long long, int> left, right;
            
            for(int j=0;j<n;j++){
                
                right[diff2[j]]++;

            }
            long long tmp;
            for(int j=0;j<n;j++){
                
                left[diff1[j]]++;
                right[diff2[j]]--;
                if(right[diff2[j]]==0){
                    right.erase(diff2[j]);
                }
                int a = points[i][j];
                if(right.empty()){
                    tmp = left.rbegin()->first+a-j;
                }else{
                    tmp = max(left.rbegin()->first+a-j, right.rbegin()->first+a+j);
                }

                diff1[j] = tmp+j;
                diff2[j] = tmp-j;
                ans = max(tmp, ans);
            }
            
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> arr ={
        {1,5},
        {2,3},
        {4,2}
    };
    cout<< s.maxPoints(arr);
}
