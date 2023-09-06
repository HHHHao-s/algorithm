#include "s.h"
/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<long long, long long> node_num;


        const long long div = 1000000007;

        for(long long x: arr){
            node_num.insert({x,1});
            
        }

        for(auto & [node, times]: node_num){
            for(auto & [item, item_times]: node_num){
                if(item*item>node){
                    break;
                }
                else if(item*item==node){
                    times = (times + item_times * item_times)%div;
                }
                else if(node%item==0 && node_num.count(node/item)==1){
                    times = (times + 2*(item_times*node_num[node/item]))%div;
                }
            }
        }

        long long ans=0;

        for(auto [node, times]: node_num){
            ans = (ans+times)%div;
        }

        return ans;

        
    }
};
// @lc code=end

int main(){


    Solution s;

    vector<int> arr={
        2, 4, 5, 10
    };

    cout << s.numFactoredBinaryTrees(arr);

    return 0;
}