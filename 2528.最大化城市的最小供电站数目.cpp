#include "s.h"
/*
 * @lc app=leetcode.cn id=2528 lang=cpp
 *
 * [2528] 最大化城市的最小供电站数目
 */

// @lc code=start
class Solution {
private:
    bool test(vector<int>& stations, long long rr, long long k, long long mn){
        deque<long long> dq;
        int n = stations.size();
        long long cur = 0;
        for(int i=0;i<rr;i++){
            dq.push_back(0);
        }

        for(int l=-rr,r=0;r<n+rr;r++){
            cur+=r<n? stations[r]:0;
            if(r-l==2*rr){
                int mid = (r+l)/2;

                if(cur<mn){
                    long long diff = mn-cur;
                    k-=diff;
                    if(k<0){
                        return false;
                    }
                    cur = mn;
                    dq.push_back((r<n? stations[r]:0)+diff);

                }else{
                    dq.push_back(r<n? stations[r]:0);
                }

                l++;
                cur-=dq.front();
                
                dq.pop_front();
            }else{
                dq.push_back(r<n? stations[r]:0);
            }
            

            
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        

        long long left = 0;
        long long right = 100000000000; 
        // 开区间写法
        while(left+1<right){
            long long mn = left+ (right-left)/2;
            if(test(stations, r, k, mn)){

                left = mn;
            }else{
                right = mn;
            }
        }
        return left;


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> stations={
        34,15,8,26,18,23
    };
    cout << s.maxPower(stations, 0, 25);
}