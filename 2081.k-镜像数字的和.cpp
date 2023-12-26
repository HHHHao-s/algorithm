#include "s.h"
/*
 * @lc app=leetcode.cn id=2081 lang=cpp
 *
 * [2081] k 镜像数字的和
 */

// @lc code=start
vector<long long> pal;

vector<vector<long long>> ks(10);
// 打表


auto init = [] {
    // 严格按顺序从小到大生成所有回文数（不用字符串转换）
    for (long long base = 1; base <= 100000; base *= 10) {
        // 生成奇数长度回文数
        for (long long i = base; i < base * 10; i++) {
            long long x = i;
            for (int t = i / 10; t; t /= 10) {
                x = x * 10 + t % 10;
            }
            pal.push_back(x);
        }
        // 生成偶数长度回文数
        if (base <= 10000) {
            for (long long i = base; i < base * 10; i++) {
                long long x = i;
                for (long long t = i; t; t /= 10) {
                    x = x * 10 + t % 10;
                }
                pal.push_back(x);
            }
        }
    }
    

    pal.push_back(100000000001); // 哨兵，防止下面代码中的 i 下标越界
    for(int k=2;k<=9;k++){
        vector<long long> finds;

        for(auto x: pal){
            // cout << x << endl;
            string trans;
            long long tx = x;
            while(x){
                
                long long digit = x%k;
                x/=k;
                trans.push_back(digit+'0');
                
                

            }
            bool can = 1;
            for(int i=0;i<trans.size()/2;i++){
                if(trans[i]!=trans[trans.size()-1-i]){
                    can =false;
                    break;
                }
            }

            if(can){
                finds.push_back(tx);
                if(finds.size()==30){
                    break;
                }
            }
            


        }
        ks[k]=move(finds);
    }
    return 0;
}();



class Solution {
private:
    

public:
    long long kMirror(int k, int n) {
        
        vector<long long> &finds = ks[k];

        
        long long ans =0;
        for(int i=0;i<n;i++){
            ans+=finds[i];
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << pal.size() << endl;
    cout << pal.back();
    // cout << s.kMirror(4,30);
}