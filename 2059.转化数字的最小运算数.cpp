#include "s.h"
/*
 * @lc app=leetcode.cn id=2059 lang=cpp
 *
 * [2059] 转化数字的最小运算数
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        vector<bool> vis(1001);

        queue<pair<long long,int>> q;
        q.push({start, 0});
        while(!q.empty()){
            
            auto [num, step] = q.front();
            
            q.pop();
            for(int i=0;i<nums.size();i++){
                int x = nums[i];
                if((num+x == goal) || (num-x == goal) || ((num^x) == goal)){
                    return step+1;
                }
                if(num+x>=0 && num+x<=1000 && !vis[num+x]){
                    
                    q.push({num+x, step+1});
                    vis[num+x] = 1;
                }
                if(num-x>=0 && num-x<=1000 && !vis[num-x]){
                    
                    q.push({num-x, step+1});
                    vis[num-x] = 1;
                }
                if((num^x)>=0 && (num^x)<=1000 && !vis[(num^x)]){
                    q.push({num^x, step+1});
                    vis[num^x]  =1;
                }
            }

        }
        return -1;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums={2,8,16};
    cout << s.minimumOperations(nums, 0, 1);
}