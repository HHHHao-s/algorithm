#include "s.h"
/*
 * @lc app=leetcode.cn id=3175 lang=cpp
 *
 * [3175] 找到连续赢 K 场比赛的第一位玩家
 */

// @lc code=start
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        
        deque<pair<int,int> > sk;
        int mx = 0;
        for(int i=0;i<skills.size();i++){
            mx = max(mx, skills[i]);
            sk.push_back({skills[i], i});
        }
        int tk = k;
        while(1){
            if(sk.front().first==mx){
                return sk.front().second;
            }
            while(tk){
                auto [l, li] = sk.front();
                sk.pop_front();
                auto [r, ri] = sk.front();
                sk.pop_front();
                if(l>r){
                    tk--;
                    sk.push_front({l, li});
                    sk.push_back({r,ri});
                }else{
                    sk.push_back({l, li});
                    sk.push_front({r,ri});
                    tk = k-1;
                    break;
                }
            }
            if(tk==0 || sk.front().first==mx){
                return sk.front().second;

            }
        }

        return 0;

    }
};
// @lc code=end

int main(){

    vector<int> arr = {4,2,6,3,9};
    cout << Solution().findWinningPlayer(arr, 2);


}
