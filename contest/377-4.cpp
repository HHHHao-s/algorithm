#include "../s.h"

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long INF = LONG_LONG_MAX -1000000;

        unordered_map<int,unordered_map<string, unordered_map<string, long long>>> mp;

        for(int i=0;i<original.size();i++){
            auto &ori = original[i];
            auto &cha = changed[i];
            if(mp[ori.size()][ori].count(cha)){
                mp[ori.size()][ori][cha] = min(mp[ori.size()][ori][cha], (long long)cost[i]);
            }else{
                mp[ori.size()][ori][cha] = cost[i];
            }
            mp[ori.size()][ori][ori] = 0;
            mp[ori.size()][cha][cha] = 0;
        }


        for(auto &[sz, strs]:mp){
            for(auto &s1:strs){
                auto &str1 = s1.first;
                for(auto &s2:strs){
                    for(auto &s3:strs){
                        if(s2.second.count(str1) && s1.second.count(s3.first)){
                            if(s2.second.count(s3.first)){
                                s2.second[s3.first] = min(s2.second[s3.first], s2.second[str1]+s1.second[s3.first]);
                            }else{
                                s2.second[s3.first] = s2.second[str1]+s1.second[s3.first];
                            }
                            
                        }
                    }
                }
            }
        }
        vector<long long> memo(source.size()+1, -1);
        function<long long(int)> dfs = [&](int count)->long long{
            if(count==0){
                return 0;
            }
            if(memo[count]!=-1){
                return memo[count];
            }
            char c1 = source[count-1];
            char c2 = target[count-1];
            long long res = INF;
            if(c1==c2){
                res = dfs(count-1);
            }
            for(auto &[sz, strs]:mp){
                if(count-sz<0){
                    continue;
                }
                auto sour = source.substr(count-sz, sz);
                auto targ = target.substr(count-sz, sz);
                if(strs.count(sour) && strs[sour].count(targ)){
                    long long tmp = dfs(count-sz);
                    if(strs[sour][targ]>LONG_LONG_MAX-tmp){
                        continue;
                    }
                    res = min(res, strs[sour][targ] + tmp);
                }
            }
            memo[count] = res;
            return res;

        };
        long long ans = dfs(source.size());
        return ans<INF?ans:-1;


    
    }
};

int main(){
    Solution s;
    vector<string> v1 = {"bcd","fgh","thh"};
    vector<string> v2 = {"cde","thh","ghh"};
    vector<int> v3 = {1,3,5};
    cout << s.minimumCost("abcdefgh","acdeeghh", v1, v2, v3);
}