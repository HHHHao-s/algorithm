#include "../s.h"

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        
        int i=0;
        int res=0;
        auto f = [&](int begin ,int end){

            for(int m=1;m<=26;m++){
                int window = m*k;
                if(window>end-begin+1){
                    break;
                }
                vector<int> appear(26), time_appear(window+1 );
                for(int i=0;i<window;i++){
                    appear[word[i+begin]-'a']++;
                }
                for(int i=0;i<26;i++){
                    time_appear[appear[i]]++;
                }
                if(time_appear[k]==m){
                    res++;
                }
                for(int l=begin,r=begin+window;r<=end;l++,r++){
                    time_appear[appear[word[l]-'a']]--;
                    appear[word[l]-'a']--;
                    time_appear[appear[word[l]-'a']]++;

                    time_appear[appear[word[r]-'a']]--;
                    appear[word[r]-'a']++;
                    time_appear[appear[word[r]-'a']]++;
                    if(time_appear[k]==m){
                        res++;
                    }

                }

            }

        };

        while(i<word.size()){
           
            int begin = i;
            i++;
            while(abs(word[i]-word[i-1])<=2 && i<word.size()){
                i++;
            }
            f(begin, i-1);

        }
        return res;

    }
};

int main(){
    Solution s;
    cout << s.countCompleteSubstrings("igigee", 2);
}