#include <vector>
#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution {
private:
    int min_cost=INT_MAX;


    void backTrace(const vector<int>& price,const vector<vector<int>>& special, vector<int>& needs, int cur_cost, int cur_big_i){
        if(cur_big_i==special.size()){
            for(int i=0;i<needs.size();i++){
                cur_cost+=price[i]*needs[i];
            }
            min_cost = min(min_cost, cur_cost);
            return ;
        }
        int new_cost = cur_cost;
        int buy=0;
        auto tmp_need = needs;
        while(1){

            // don't buy the special at first
            bool con=true;
            
            for(int i=0;i<special[cur_big_i].size()-1;i++){
                int need = needs[i] - special[cur_big_i][i]*buy;
                if(need>=0){
                    needs[i] = need;
                }else{
                    con=false;
                    break;
                }
            }
            if(con){
                if(cur_cost+buy*special[cur_big_i].back()>=min_cost){
                    // 剪枝
                    break;
                }
                backTrace(price, special, needs, cur_cost+buy*special[cur_big_i].back(), cur_big_i+1);
                needs = tmp_need;
                buy++;
                continue;
            }else{

                break;
            }
        }

    }

public:
    int shoppingOffers(const vector<int>& price,const vector<vector<int>>& special, vector<int>& needs) {
        
        backTrace(price, special, needs, 0, 0);

        return min_cost;

    }
};
// @lc code=end
