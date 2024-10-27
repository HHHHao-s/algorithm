#include "../s.h"

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        vector<long long> cnt(26);
        for(char c: s){
            cnt[c-'a']++;
        }
        long long MOD = 1e9+7;
        for(int i=0;i<t;i++){
            vector<long long> nt(26);
            for(int j=0;j<26;j++){

                int ct = cnt[j];
                if(j==25){
                    nt[0] = (nt[0] + ct)%MOD;
                    nt[1] = (nt[1] + ct)%MOD;
                }else{
                    nt[j+1] = (nt[j+1] + ct)%MOD;
                }
            }
            cnt = std::move(nt);

        }
        long long ans=0;
        for(long long ct:cnt){
            ans = (ans+ct)%MOD;
        }
        if(ans<0){
            ans+=MOD;
        }
        return ans;

    }
};
int main(){
    cout << Solution().lengthAfterTransformations("abcyy",2);
}