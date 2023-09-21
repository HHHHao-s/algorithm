#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){

    std::string line;
    std::getline(std::cin, line); // read a line of integers from standard input
    std::istringstream iss(line);
    int num;
    vector<int> arr;
    while(iss>>num){
        arr.push_back(num);
    }

    int n=arr.size();
    vector<vector<int>> dp(n+1,{0,0});
    for(int i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][1]+arr[i-1], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
    }

    cout << max(dp[n][0], dp[n][1]);


    return 0;
}