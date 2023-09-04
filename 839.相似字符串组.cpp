#include "s.h"
/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
class UnionFind{
public:
    vector<int> par;
    UnionFind(int n){
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int Find(int x){
        return par[x]==x?x:(par[x]=Find(par[x]));
    }

    void Merge(int x,int y){
        int fx = Find(x);
        int fy = Find(y);
        if(fx!=fy){     
            par[fy] = fx;      
        }
    }
};

class Solution {
private:
    int sz;
    int probe(const string &a,const string &b){
        int num = 0;
        for (int i = 0; i < sz; i++) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return 1;
    }

public:
    int numSimilarGroups(const vector<string>& strs) {

        int n = strs.size();
        sz = strs[0].size();

        UnionFind u1(n);

        for(int i=0;i<n;i++){
            string s1 = strs[i];
            for(int j=i+1;j<n;j++){
                string s2 = strs[j];
                if(u1.Find(i)==u1.Find(j)){
                    continue;
                }
                if(probe(s1,s2)){
                    u1.Merge(i,j);
                }
            }

        }

        int cnt=0;

        for(int i=0;i<n;i++){
            if(u1.par[i]==i){
                cnt++;
            }
        }

        return cnt;


    }       
};
// @lc code=end

int main(){

    Solution s;

    cout << s.numSimilarGroups({
        "tars","rats","arts"
    });


    return 0;
}