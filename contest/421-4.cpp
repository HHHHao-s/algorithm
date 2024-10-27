#include "../s.h"

class Solution {
public:
    long long MOD = 1e9+7;

    vector<vector<long long >> mul(vector<vector<long long >> a, vector<vector<long long >>b){
        int n = a.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result[i][j] = (result[i][j]+ (a[i][k] * b[k][j])%MOD)%MOD;
                }
            }
        }
        return result;


    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {

        
        vector<long long> cnt(26), tt(26, t);
        for(char c: s){
            cnt[c-'a']++;
        }

        vector<vector<long long >> matrix(26, vector<long long>(26));

        for(int i=0;i<26;i++){

            int cur = nums[i];

            for(int j=1;j<=cur;j++){

                matrix[i][(i+j)%26] = 1;
            }

        }

        

        vector<vector<long long >> result(26, vector<long long>(26));
        for(int i=0;i<26;i++){
            result[i][i] = 1;
        }

        vector<vector<long long>> base= matrix;
        while (t > 0) {
            if (t % 2 == 1) {
                result = mul(result, base);
            }
            base = mul(base, base);
            t = t / 2;
        }
        vector<long long > ct(26);
        for(int i=0;i<26;i++){

            for(int j=0;j<26;j++){

                ct[i] = (ct[i]+ (cnt[j]*result[j][i])%MOD)%MOD;

            }

        }
        long long ans= 0;
        for(long long c: ct){
            ans = (ans+c)%MOD;
        }
        if(ans<0){
            ans+=MOD;
        }
        return ans;
        




    }
};

int main(){
    vector<int> nums=  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    cout <<Solution().lengthAfterTransformations("azbk",1, nums);
}