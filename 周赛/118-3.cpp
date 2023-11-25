#include "../s.h"

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        const int INF= 100000000;
        unordered_map<int, unordered_map<int, int>> memo;

        function<int(int, int)> find = [&](int index, int min_need){
            if(memo[index].count(min_need)){
                return memo[index][min_need];
            }
            if(index<0){
                if(min_need==0){
                    return 0;
                }else{
                    return INF;
                }
            }
            if(index+1<min_need){
                memo[index][min_need]=INF;
                return INF;
            }else{
                int buy_this = find(index-1, 0) + prices[index];
                int not_buy = find(index-1, min_need+1);
                memo[index][min_need] = min(buy_this, not_buy);
                return min(buy_this, not_buy);
            }
            memo[index][min_need]=INF;
            return INF;


        };

        return find(prices.size()-1, 0);



    }
};

