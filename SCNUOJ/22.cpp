#include <vector>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <string.h>
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

    void backTrace(const vector<int>& price,const vector<vector<int>>& special, vector<int>& needs, int cur ,int cur_price){

        if(cur == special.size()){
            for(int i=0;i<needs.size();i++){
                cur_price+=needs[i]*price[i];
               
            }
            min_cost=min(min_cost, cur_price);
            return ;
        }

        int i=0;// don't buy at first
        while(1){
            if(cur_price + i*special[cur].back()>min_cost){
                break;
            }
            
            for(int j=0;j<needs.size();j++){
                if(needs[j]-i*special[cur][j]<0){
                    return;
                }
            }
            for(int j=0;j<needs.size();j++){
                needs[j]-=i*special[cur][j];            
            }
            backTrace(price, special, needs, cur+1, cur_price+i*special[cur].back());
            for(int j=0;j<needs.size();j++){
                needs[j]+=i*special[cur][j];            
            }
            i++;

        }

    }

public:
    int shoppingOffers(const vector<int>& price,const vector<vector<int>>& special, vector<int>& needs) {
        
        backTrace(price, special, needs, 0, 0);        

        return min_cost;

    }
};
// @lc code=end

int main(){

    char buf[100];
    char*pbuf = buf;

    scanf("%[^\n]", buf);
    int a;
    int b=-1;
    vector<int> price;
    while(sscanf(pbuf, "%d", &a)){
        pbuf = strchr(pbuf, ' ');
        
        if(b!=-1){
            price.push_back(b);
        }
        b = a;
        if(pbuf!=nullptr){
            pbuf++;
        }else{
            break;
        }
    }
    vector<vector<int>> special;
    for(int i=0;i<a;i++){
        vector<int> one;
        int num;
        for(int j=0;j<price.size()+1;j++){
            scanf("%d", &num);
            one.push_back(num);
        }
        special.emplace_back(std::move(one));
    }
    vector<int> needs;

    for(int i=0;i<price.size();i++){
        int num;
        scanf("%d", &num);
        needs.push_back(num);
    }
    Solution s;

    printf("%d",s.shoppingOffers(price, special, needs));

    return 0;
}