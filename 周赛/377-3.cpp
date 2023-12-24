#include "../s.h"

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = INT_MAX>>2;
        vector<vector<long long>> mp(26,vector<long long>(26,INF));
        for(int i=0;i<26;i++){
            mp[i][i]=0;
        } 
        for(int i=0;i<original.size();i++){

            mp[original[i]-'a'][changed[i]-'a'] = min(mp[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);

        }

        for(int k=0;k<26;k++){
            for(int j=0;j<26;j++){
                for(int i=0;i<26;i++){
                    if(mp[i][k]!=INF && mp[k][j]!=INF && mp[i][k]+mp[k][j]<mp[i][j]){
                        mp[i][j] = mp[i][k]+mp[k][j];
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.size();i++){
            char sor = source[i];
            char tar = target[i];
            if(mp[sor-'a'][tar-'a']==INF){
                return -1;
            }
            ans += mp[sor-'a'][tar-'a'];
        }
        return ans;

    }
};

int main(){

    Solution s;
    
    
}