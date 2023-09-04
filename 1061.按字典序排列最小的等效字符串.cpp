#include "s.h"
/*
 * @lc app=leetcode.cn id=1061 lang=cpp
 *
 * [1061] 按字典序排列最小的等效字符串
 */

// @lc code=start
class UnionFind{
private:
    vector<int> par;
public:
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
            if(fx<=fy){
                par[fy] = fx;
            }else{
                par[fx] = fy;
            }
            
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        UnionFind u1(26);

        for(int i=0;i<n;i++){
            int fir = s1[i]-'a';
            int las = s2[i]-'a';

            if(fir!=las){
                u1.Merge(fir,las);
                
            }
        }

        string ans;
        ans.reserve(baseStr.size());

        for(auto c: baseStr){
            int num = c-'a';
            int fa = u1.Find(num);
            if(fa!=num){
                ans.push_back(fa+'a');
            }else{
                ans.push_back(c);
            }

        }

        return ans;


    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.smallestEquivalentString("parker","morris","parser");


    return 0;
}