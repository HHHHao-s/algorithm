#include "s.h"
/*
 * @lc app=leetcode.cn id=2732 lang=cpp
 *
 * [2732] 找到矩阵中的好子集
 */

// @lc code=start
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> a[1<<5];
        vector<int> ans;
        int m=grid.size();
        int n=grid[0].size();
        // 当k==2时，这两行&为0
        // 当k==3时，标准为1，删去任意行，还是满足k==2的情况，不考虑
        // 当k==4时，因为任意两行&不能为0
        // 所以考虑最少1的数，10000，其他的数第一列必须为1，不满足
        // 11000，有10___,01___,因为任意两行&不为0，第四行无论怎么填，都会超过2
        // 11100，有10011,01011,因为考虑最少的1，所以第四行无论怎么填，都会超过2
        // 答案就是求是否有全零和是否有两行&为0
        for(int i=0;i<m;i++){
            int s=0;
            for(auto c:grid[i])
                s=(s<<1)+c;
            if(s==0){
                ans.push_back(i);
                return ans;
            }
            a[s].push_back(i);
        }
        for(int i=0;i<(1<<n);i++){
            if(a[i].size()==0) 
                continue;
            for(int j=i+1;j<(1<<n);j++){
                if(a[j].size()==0) 
                    continue;
                if((i&j)==0){
                    ans.push_back(a[i][0]);
                    ans.push_back(a[j][0]);
                    sort(ans.begin(),ans.end());
                    return ans;
                }
            }
        }
        return ans;
    }
};

// @lc code=end

