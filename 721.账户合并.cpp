#include "s.h"
/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
private:
    vector<int> bc;

    int find(int x){
        return x==bc[x]?x:(bc[x]=find(bc[x]));
    }

    void merge(int x, int fa){
        int px = find(x);
        int py = find(fa);
        if (px != py) {
            bc[px] = py;
        }
    }


public:


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        bc.resize(n);
        for(int i=0;i<n;i++){
            bc[i] = i;
        }

        // 邮箱到id，其中id为此邮箱对应的account的序号（index）
        // 当一个account的邮箱已经出现过了，就将此id并入第一次出现的id
        
        map<string, int> m;

        for(int i=0;i<n;i++){
            auto strings = accounts[i];
            int n = strings.size();
            for(int j=1;j<n;j++){
                string s = strings[j];
                if(m.count(s)==0){
                    m[s] = i;
                }else{
                    merge(i, m[s]);
                }
            }
        }

        // 此时m中string按照邮箱asicii码排列好

        vector<vector<string>> ret;


        // 将id与ret中的index对应起来
        unordered_map<int,int> id_to_index;

        for(int i=0;i<n;i++){
            if(find(i)==i){
                string name = accounts[i][0];
                ret.push_back({name});
                id_to_index[i] = ret.size()-1;
            }

        }

        // 将已经排好序的email按照相同的集合放入结果集
        for(auto it: m){
            auto [email, id] = it;
            ret[id_to_index[find(id)]].push_back(email);
        }

        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<string>> accounts ={{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    vector<vector<string>> accounts2 = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
    print2d(s.accountsMerge(accounts2));


    return 0;
}