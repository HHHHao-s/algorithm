#include "../s.h"


class Solution {
public:
    int maximumLength(string s) {
        
        int n = s.size();
        int l=0,r=0;
        vector<pair<char, int>> infos;

        while(r<n){

            while(r<n&&s[r]==s[l]){
                r++;

            }
            infos.push_back({s[l], r-l});
            l=r;

        }

        vector<map<int, int>> cs(26);
        int ans=0;
        for(auto [c, len]: infos){
            if(len>=3){
                ans=max(ans, len-2);
                cs[c-'a'][len]++;
            }else if(len==2){
                
                cs[c-'a'][len]++;
                cs[c-'a'][1]+=2;
                if(cs[c-'a'][1]>=3){
                    ans=max(ans,1);
                }
            }else{
                cs[c-'a'][1]++;
                if(cs[c-'a'][1]>=3){
                    ans=max(ans, 1);
                }
            }
            
        }
        
        for(int i=0;i<26;i++){
            int ct=0;
            cs[i].erase(1);
            int last=0;
            for(auto it=cs[i].rbegin();it!=cs[i].rend();it++){
                
                auto [len,times] = (*it);
                if(!last){
                    if(times>=3){
                        ans = max(ans, len);
                        break;
                    }else if(times==2){
                        ans = max(ans, len-1);
                        
                    }else{
                        last=1;
                    }
                }else{
                    ans = max(ans, len);
                }
                
            }

        }
        return ans==0?-1:ans;

    }
};

int main(){
    Solution s;
    cout << s.maximumLength("bbc");
}