#include "s.h"
/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(const vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            vector<int> sum(n);
            for(int j=i;j<m;j++){
                
                for(int k=0;k<n;k++){
                    sum[k] += matrix[j][k];
                }
                unordered_map<int, int> mp;
                mp[0]=1;
                int pre=0;
                for(int k=0;k<n;k++){
                    pre+=sum[k];
                    if(mp.count(pre-target)!=0){
                        ans+=mp[pre-target];
                    }
                    
                    mp[pre]++;
                }
            }
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.numSubmatrixSumTarget({
        {0,1,0},
        {1,1,1},
        {0,1,0}
    }, 0);

    return 0;
}