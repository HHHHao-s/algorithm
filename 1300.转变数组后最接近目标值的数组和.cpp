#include "s.h"
/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 *
 * [1300] 转变数组后最接近目标值的数组和
 */

// @lc code=start
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        

        map<int, int> m;
        int n = arr.size();

        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }

        // vector<long long> pre;

        // int index=0;
        long long sum = 0;
        long long cnt =0;
        long long last=0;
        int ans = 0;
        long long diff=target;
        for(auto it=m.begin(); it!=m.end();it++){

            long long l = target-sum;
            long long dev = l/(n-cnt);
            if(last <=dev &&dev<= it->first){
                if(abs(sum+dev*(n-cnt)-target)<diff){
                    ans = dev;
                    diff = abs(sum+dev*(n-cnt)-target);
                }
                if(abs(sum+(dev+1)*(n-cnt)-target)<diff){
                    ans = dev+1;
                    diff = abs(sum+(dev+1)*(n-cnt)-target);
                }
            }else if(dev>it->first){
                if(abs(sum+it->first*(n-cnt)-target)<diff){
                    ans = it->first;
                    diff = abs(sum+it->first*(n-cnt)-target);
                }
            }else{
                if(abs(sum+last*(n-cnt)-target)<diff){
                    ans = last;
                    diff = abs(sum+last*(n-cnt)-target);
                }
            }
            sum += it->first * it->second;
            cnt += it->second;
            last = it->first;

            // pre[index++] = sum;
        }

        return ans;

    }
};
// @lc code=end

int main(){

    vector<int> v1 ={
        4,9,3
    };
    vector<int> v2 ={
        60864,25176,27249,21296,20204
    };
    vector<int> v3 ={
        2,3,5
    };

    Solution s;
    // cout << s.findBestValue(v1, 10);
    // cout << s.findBestValue(v2, 56803);
    cout << s.findBestValue(v3, 11);
    return 0;
}
