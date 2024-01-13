#include "s.h"
/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> strs(26);
        for(char c: s){
            strs[c-'a']++;
        }
        string ans;
        int top = 25;
        for(int i=25;i>=0;i--){
            if(strs[i]>0){
                top = i;
                break;
            }
        }
        int cnt = 0;
        while(ans.size()<s.size()){
            int index = top;
            
            while(ans.size()<s.size()&&cnt<repeatLimit&&strs[index]>0){
                ans.push_back('a'+index);
                strs[index]--;
                cnt++;
            }
            if(ans.size()==s.size()){
                break;
            }
            if(cnt==repeatLimit){
                int found=-1;
                for(int j=index-1;j>=0;j--){
                    if(strs[j]>0){
                        found=j;
                        strs[j]--;
                        ans.push_back('a'+j);
                        break;
                    }
                }
                if(found==-1){
                    return ans;
                }
                if(strs[index]==0){
                    cnt=1;
                    top = found;
                    continue;
                }
            }
            if(strs[index]==0){
                for(int j=index-1;j>=0;j--){
                    if(strs[j]>0){
                        top = j;
                        break;
                    }
                }
            }
            cnt = 0;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.repeatLimitedString("robnsdvpuxbapuqgopqvxdrchivlifeepy", 2);
}