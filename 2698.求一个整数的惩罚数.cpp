#include "s.h"
/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
class Solution {
private:
    

    // int back_trace(string &s, int target, vector<int>& di, int k, int high){

    //     if(di.size()==k){
    //         int sum = atoi(s.substr(0,di[0]+1).c_str());
    //         for(int i=1;i<k;i++){
    //             sum += atoi(s.substr(di[i-1]+1, di[i]-di[i-1]).c_str());
    //         }
    //         sum+=atoi(s.substr(di.back()+1,s.size()-di.back()-1).c_str());
    //         return sum==target;
    //     }

    //     for(int i=high;i<s.size()-k+di.size();i++){
    //         di.push_back(i);            
    //         if(back_trace(s, target, di, k, i+1)){
    //             return 1;
    //         }
    //         di.pop_back(); 
    //     }   
    //     return 0;
        

    // }

    // int find(string &s, int target){

    //     int n = s.size();

    //     for(int k=n-1;k>=1;k--){
    //         vector<int> di;
    //         if(back_trace(s, target, di,k,0)){
    //             return target*target;
    //         }
    //     }
    //     return 0;


    // }

public:
    int punishmentNumber(int n) {
        vector<int> all= {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000};
     
        auto pos = upper_bound(all.begin(),all.end(), n);
        int ans =0;
        for(auto it=all.begin();it!=pos;it++){
            ans += *it*(*it);
        }
        return ans;
        
       


    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.punishmentNumber(1000);

}