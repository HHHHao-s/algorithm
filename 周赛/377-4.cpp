#include "../s.h"

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const int INF = INT_MAX>>2;

        int cn=original.size();
        
        unordered_map<string,int> str_mp;
        int n = source.size();

        for(auto &ori: original){
            if(ori.size()>n){
                continue;
            }
            if(!str_mp.count(ori)){
                int sz = str_mp.size();
                str_mp[ori]=sz;
            }
        }

        for(auto &cha: changed){
            if(cha.size()>n){
                continue;
            }
            if(!str_mp.count(cha)){
                int sz = str_mp.size();
                str_mp[cha]=sz;
            }

        }

        
        vector<vector<long long>> mp(str_mp.size(),vector<long long>(str_mp.size(),INF)); 
        for(int i=0;i<str_mp.size();i++){
            mp[i][i]=0;
        }   
        for(int i=0;i<cn;i++){
            if(!str_mp.count(original[i])||!str_mp.count(changed[i])){
                continue;
            }

            mp[str_mp[original[i]]][str_mp[changed[i]]] = min(mp[str_mp[original[i]]][str_mp[changed[i]]], (long long)cost[i]);

        }
        cn = str_mp.size();

        for(int k=0;k<cn;k++){
            for(int j=0;j<cn;j++){
                for(int i=0;i<cn;i++){
                    if(mp[i][k]!=INF && mp[k][j]!=INF  && mp[i][k]+mp[k][j]<mp[i][j]){
                        mp[i][j] = mp[i][k]+mp[k][j];
                    }
                }
            }
        }   
        string stmp;
        string ttmp;

        // for(int i=0;i<n;i++){
        //     if(source[i]==target[i]){
        //         continue;
        //     }
        //     stmp.push_back(source[i]);
        //     ttmp.push_back(target[i]);
        // }
        // source = stmp;
        // target = ttmp;
        // n = stmp.size();

        vector<vector<long long>> dp(n, vector<long long>(n, INF));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                string subsor = source.substr(i, j-i+1);
                string subtar = target.substr(i, j-i+1);
                if(subsor==subtar){
                    dp[i][j]=0;
                    if(j<n-1)
                        dp[i][n-1] = min(dp[i][j]+dp[j+1][n-1], dp[i][n-1]);
                }
                if(str_mp.count(subsor) && str_mp.count(subtar)){
                    long long cst = mp[str_mp[subsor]][str_mp[subtar]];
                    
                    dp[i][j] = min(dp[i][j], cst);
                    if(j<n-1)
                        dp[i][n-1] = min(dp[i][j]+dp[j+1][n-1], dp[i][n-1]);
                }
            }
        }
        if(dp[0][n-1]==INF){
            return -1;
        }
        return dp[0][n-1];


    
    }
};

int main(){
    Solution s;
    vector<string> v1 = {"bcd","fgh","thh"};
    vector<string> v2 = {"cde","thh","ghh"};
    vector<int> v3 = {1,3,5};
    cout << s.minimumCost("abcdefgh","acdeeghh", v1, v2, v3);
}