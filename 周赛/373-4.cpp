#include "../s.h"
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        
        int d=1;
        for(int d=1;;d++){
            if((d*d)%(4*k)==0){
                k=d;
                break;
            }
        }
        // 现在要满足总长度能被k整除
        unordered_map<int,unordered_map<int,int>> mp; // mp[presum][len]
        int pre=0;
        int ans=0;
        int i=0;
        mp[0][0] =1;
        for(auto c: s){
            i++;
            if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u'){
                pre++;
            }else{
                pre--;
            }
            if(mp.count(pre) && mp[pre].count(i%k)){
                ans+= mp[pre][i%k];
            }
            mp[pre][i%k]++;
            
        }
        return ans;

    }
};

int main(){
    Solution s;

    cout << s.beautifulSubstrings("baeyh", 2);
    return 0;
}