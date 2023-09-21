#include "s.h"

// class Solution {

// private:

//     bool check(int n, int budget, int make, vector<int>& composition, vector<int>& stock, vector<int>& cost){
//         int cur_cost = 0;
//         for(int i=0;i<n;i++){
//             if(composition[i]*make>stock[i]){
//                 cur_cost+=(composition[i]*make-stock[i])*cost[i];
//                 if(cur_cost>budget){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     int solveOne(int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost){
//         int low=1;
//         auto min_e = *min_element(stock.begin(), stock.end());
//         int high = budget/n + min_e;
//         int ans=0;
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             if(check(n,budget,mid,composition,stock,cost)){
//                 ans = low;
//                 low = mid+1;
//             }else{
//                 high = mid-1;
//             }
//         }
//         return ans;
//     }

// public:
//     int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
//         int ans=0;
//         for(int i=0;i<k;i++){
//             ans = max(ans,solveOne(n, budget, composition[i], stock, cost));
//         }
//         return ans;

//     }
// };

class Solution {

private:

    bool check(int n, int budget, unsigned long long make, vector<int>& composition, vector<int>& stock, vector<int>& cost){
        unsigned long long cur_cost = 0;
        for(int i=0;i<n;i++){
            if(composition[i]*make>stock[i]){
                cur_cost+=(composition[i]*make-stock[i])*cost[i];
                if(cur_cost>budget){
                    return false;
                }
            }
        }
        return true;
    }

    int solveOne(int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost){
        int low=1;
        auto min_e = *min_element(stock.begin(), stock.end());
        int high = budget + min_e;
        int ans=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(n,budget,mid,composition,stock,cost)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }

public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans=0;
        for(int i=0;i<k;i++){
            ans = max(ans,solveOne(n, budget, composition[i], stock, cost));
        }
        return ans;

    }
};

int main(){

    Solution s;

    vector<vector<int>> composition={
        {1,1,1},
        {1,1,10},
    };
    vector<int> stock={
        0,0,0
    };
    vector<int> cost={
        1,2,3
    };

    cout << s.maxNumberOfAlloys(3,2,15, composition, stock, cost);


    return 0;
}