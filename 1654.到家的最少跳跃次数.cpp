#include "s.h"
/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */

// @lc code=start
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int g=  gcd(a,b);
        if(x%g!=0){
            return -1;
        }
        int top = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b;
        vector<vector<int>> seen(2, vector<int>(top));
        for(int f: forbidden){
            seen[0][f] = 1;
            seen[1][f] =1;
        }

        queue<pair<int,int>> q;

        q.push({0,0});
        seen[0][0] = 1;
        int step= 0;
        while(!q.empty()){
            
            int sz = q.size();
            for(int j=0;j<sz;j++){
                
                auto [pos, type] = q.front();
                if(pos==x){
                    return step;
                }
                q.pop();
                if(type==0){
                    if(pos-b >=0 && !seen[1][pos-b]){
                        q.push({pos-b, 1});
                        seen[1][pos-b] =1 ;
                    }
                    
                }
                if( pos+a < top &&!seen[0][pos+a]){
                    q.push({pos+a, 0});
                    seen[0][pos+a] = 1;
                }
                
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> forbidden={14,4,18,1,15};
    cout << s.minimumJumps(forbidden, 3, 15, 9);
}