#include <bits/stdc++.h>

using namespace std;



vector<vector<string>> f(vector<string> words, string search_word){
    int n = search_word.size();
    vector<set<string>> ans(n);

    
    for(auto &word: words){

        for(int i=0;i<n && i< word.size();i++){
            char c = word[i];
            if(search_word[i] == c){
                ans[i].insert(word);
                if(ans[i].size()>3){
                    ans[i].erase(*ans[i].rbegin());
                }
            }else{
                break;
            }
        }

    }

    vector<vector<string>> ret;
    for(int i=0;i<n;i++){

        vector<string> tmp;
        for(auto &s: ans[i]){
            tmp.push_back(s);
        }
        ret.emplace_back(move(tmp));
    }
    return ret;

}

int main(){
    

    vector<string> words={
        "money", "monday", "monkey", "mother", "map", "monkeys","mobile", "monetary"
    };
    auto ret = f(words, "money");
    for(auto &each: ret){
        for(auto &s: each){
            cout << s << ' ';
        }
        cout << endl;
    }
    

    return 0;
}