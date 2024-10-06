#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals
#include <deque>
#include <time.h>
#include <random>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int count_of_binary_palindrome_number(int num) {
        // write code here
        if(num==1 || num==2){
            return 2;
        }
        if(num==3 || num==4){
            return 3;
        }
        
        int tn= num;
        while(tn){
            s.push_back(tn%2);
            tn/=2;
        }
        reverse(s.begin(), s.end());
        int n = s.size();
        int ans=0;

        vector<int> tmp(5);
        tmp[1]=2;
        tmp[2]=1;
        tmp[3]=tmp[4] =2;


        for(int len =1;len<=n;len+=2){
            if(len<n){
                if(len<=4){
                    ans+=tmp[len];
                }else{
                    ans+= 1<<((len-3)/2+1);
                }
            }else if(len==n){

                vector<int> all;
                int tmp2 = (1<<(len-1)) +1;
                for(int k=0;k<(1<<(len-3)/2);k++){
                    int r=0;
                    for(int j=0;(1<<j)<=k;j++){
                        r = (r<<1) | ((k&(1<<j))>>j);
                    }
                    all.push_back( tmp2 | (k<<((len/2)+1)) | (r<<(1)));
                    all.push_back( tmp2 | (k<<((len/2)+1)) | (r<<(1)) | (1<<(len/2)));
                }
                sort(all.begin(), all.end());
                ans+= lower_bound(all.begin(),all.end(), num)-all.begin() +1 ;
            }
            if(len+1<n){
                if(len<=4){
                    ans+=tmp[len+1];
                }else{
                    ans += 1<<((len+1)/2);
                }
            }else if(len+1==n){
                len = len+1;
                vector<int> all;
                int tmp2= (1<<(len-1)) +1;
                for(int k=0;k<(1<<(len-2)/2);k++){
                    int r=0;
                    for(int j=0;(1<<j)<=k;j++){
                        r = (r<<1) | ((k&(1<<j))>>j);
                    }
                    all.push_back( tmp2 | (k<<((len/2))) | (r<<(1)));
                }
                sort(all.begin(), all.end());
                ans+= lower_bound(all.begin(),all.end(), num)-all.begin();
                len--;
            }
            

        }
        return ans;
        
    }
    vector<long long> memo;
    vector<int> s;
};
    

int main(){
    
    cout << Solution().count_of_binary_palindrome_number(17);
}



