#include "s.h"
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pre(n+1), right(n, n);
        vector<int> cnt(2);
        int i=0;
        for(int j=0;j<n;j++){
            cnt[s[j]-'0']++;
            while(cnt[0]>k && cnt[1]>k){
                cnt[s[i]-'0']--;
                right[i] = j;
                i++;
            }
            pre[j+1] = pre[j] + j-i+1;
        }
        vector<long long> ans;
        for(auto &q: queries){

            int l = q[0],r = q[1];

            if(right[l]-1>r){
                ans.push_back(1ll * (r-l+2)*(r-l+1)/2);
            }else{
                long long p1 = 1ll * (right[l]-l)*(right[l]-l+1)/2;
                long long p2 = pre[r+1] - pre[right[l]];
                ans.push_back(p1 + p2);
            }

        }
        return ans;

        

    }
};

int main(){
    vector<vector<int>> q={
        {0,6}
    };
    printArr( Solution ().countKConstraintSubstrings("0001111", 2 ,q));
}