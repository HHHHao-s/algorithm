#include "../s.h"

constexpr int mx = 1000000000;
class Trie{
public:
    Trie() = delete;
    Trie(int range_):range(range_) ,sons(range_){

    }

    void insert(const string& str, int cost){
        Trie *cur = this;
        for(char c: str){
            if(cur->sons[c-'a']==nullptr){
                cur->sons[c-'a'] = new Trie(range);
            }
            cur = cur->sons[c-'a'];

        }
        cur->cost=min(cur->cost,cost);
    }

    ~Trie(){
        for(auto t: sons){
            delete t;
        }
    }


    int range{0};
    int cost{mx};
    vector<Trie*> sons;
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        int n = target.size();
        vector<int> dp(n+1, mx);

        Trie *t = new Trie(30);
        int k=0;
        for(auto &s: words){

            t->insert(s, costs[k]);
            k++;
        }

        dp[n] = 0;

        for(int i=n;i-->0;){

            

            Trie *cur = t;
            for(int j=i;j<=n && cur!=nullptr;j++){
                
                if(cur->cost!=-1){
                    dp[i] = min(dp[j]+cur->cost, dp[i]);
                }
                if(j<n){
                    cur=cur->sons[target[j]-'a'];
                }
                
            }

        }

        return dp[0]==mx?-1:dp[0];

    }
};

int main(){
    Solution s;
    // vector<string> words={"abdef","abc","d","def","ef"};
    // vector<int> costs={100,1,1,10,5};
    // cout << s.minimumCost("abcdef", words,costs);

    vector<string> words={"zzz","zz","z"};
    vector<int> costs={100,1,1};
    cout << s.minimumCost("aaaa", words,costs);
}