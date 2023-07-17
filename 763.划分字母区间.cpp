#include "s.h"
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:

    
   


    vector<int> partitionLabels(string s) {
        vector<int> ret;
        if(s.size()==1){
            ret.push_back(1);
            return ret;
        }
        int last[26];
        int n = s.size();
        for(int i=0;i<n;i++){
            last[s[i]-'a'] = i;
        }
        int end= 0, far = 0, begin = 0;
        for(int i=0;i<n;i++){
            far = max(far, last[s[i]-'a']);
            if(far>end){
                end = far;
            }
            if(end == i){
                ret.push_back(i-begin+1);
                begin = i+1;

            }
            
        }

        return ret;


    }
};
// @lc code=end
int main(){

    Solution s;
    printArr(s.partitionLabels("ababcbacadefegdehijhklijp"));

    return 0;
}
