#include "s.h"
/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0;i<n;i++){
            m[row[i]] = i;
        }
        for(int i=0;i<n;i+=2){
            int t = row[i];
            int need=-1;
            if(t&1){
                need = t-1;
            }else{
                need = t+1;
            }
            if(row[i+1]!=need){
                int val = row[i+1];
                int pos_need = m[need];
                swap(row[pos_need], row[i+1]);
                ans++;
                m[val] = pos_need;
                
            }
        }
        
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;
    vector row = {0,2,4,6,7,1,3,5};
    cout << s.minSwapsCouples(row);
    
}