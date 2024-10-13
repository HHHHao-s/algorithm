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



int main(){


    int n;
    cin >> n;
    long long ans = 0;
    unordered_map<long long ,long long > cnt;
    
    for(int i=0;i<n;i++){
        long long num;
        cin >> num;
        long long mb = num & (-num);
        cnt[mb]++;
        
    }


    for(int i=1;i<=16;i++){
        ans+=cnt[(1ll<<i)]*i;
    }
    cout << ans << endl;
    return 0;
}



