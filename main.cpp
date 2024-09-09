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

using namespace std;

int f(long long x){
    int r = 0;
    for(int i=0;i<63;i++){
        if(x & (1ll<<i)){
            r++;
        }
    }

    return r;
}

long long g(long long x){
    long long ret =x;
    int stage = 0;
    int cnt= 0;
    for(int i=0;i<63;i++){

        if(x & (1ll<<i)){
            if(stage==0){
                stage=1;
            }else{
                cnt++;
            }
        }else{
            if(stage==1){
                ret &= ~((1ll<<i)-1);
                ret |= 1ll << i;
                for(int j=0;j<cnt;j++){
                    ret |= 1ll << j;
                }

                break;
            }
        }

    }
    return ret;

}

int main() {

    int n;
    cin >> n;
    vector<long long> arr(n);
    vector<set<long long>> each(63);
    for(int i=0;i<n;i++){
        cin >>arr[i];
        each[f(arr[i])].insert(arr[i]);
    }
    int mx = 0;
    for(int i=1;i<63;i++){
        if(each[i].size()<=mx){
            continue;
        }
        int tmp=1;
        for(auto l=each[i].begin();l!=each[i].end();){
            auto r = l;
            r++;
            int sz = 1;
            while(r!=each[i].end()){
                auto last = r;
                last--;

                long long lv = *last;
                long long rv = *r;

                if(g(lv)==rv){
                    r++;
                    sz++;
                    tmp = max(tmp, sz);
                }else{

                    break;
                }
            }
            l=r;
            tmp = max(tmp, sz);
        }
        mx = max(tmp,mx);
    }
    cout << mx;



}