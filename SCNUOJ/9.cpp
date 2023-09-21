#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string s;
    int n;
public:
    pair<int,int> expand(int l, int r){
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
        }
        return {l+1,r-1};
    }

    string longestPalindrome(string _s){
        s = _s;
        n = _s.size();
        int start = 0;
        int end = 0;

        for(int i=0;i<n;i++){
            auto [l1, r1] = expand(i,i);
            auto [l2, r2] = expand(i,i+1);
            if(r1-l1 > end-start){
                start = l1;
                end = r1;
            }
            if(r2-l2>end-start){
                start = l2;
                end = r2;
            }
            
        }

        return s.substr(start, end-start+1);
    }
};

int main(){

    string s;

    cin >> s;

    Solution solu;

    cout <<  solu.longestPalindrome(s);


    return 0;
}