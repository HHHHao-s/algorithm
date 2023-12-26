#include "s.h"
/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */

// @lc code=start
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        unordered_map<int, int> memo;

        
        auto checkRow = [&](int row, int status){
            for(int i=0;i<n;i++){
                if(status & (1<<i) && seats[row][i]=='#'){
                    return false;
                }
            }

            if((status & (status>>1)) || (status & (status<<1))){
                return false;
            }
            return true;

        };

        auto checkUpper = [&](int status, int upperRow){

            if(upperRow & (status<<1) || upperRow & (status>>1)){
                return false;
            }
            return true;

        };

        function<int(int ,int)> dfs = [&](int row, int status){
            int key =( row<<n) | status;
            if(memo.count(key)==0){

                if(!checkRow(row, status)){
                    memo[key] = 0;
                }else{
                    if(row==0){
                        memo[key] = __builtin_popcount(status);
                        return memo[key];
                    }
                    int cur_people = __builtin_popcount(status);
                    int mx = 0;
                    for(int upStates=0;upStates<(1<<n);upStates++){
                        if(checkUpper(status, upStates)){
                            
                            mx = max(mx,cur_people+ dfs(row-1, upStates));
                            
                        }
                    }
                    memo[key] = mx;
                }

            }
            return memo[key];

        };
        int mx = 0;
        for(int i=0;i<(1<<n);i++){
            mx = max(mx, dfs(m-1, i));

        }
        return mx;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<char>> seats={
        {'#','.','#','#','.','#'},
        {'.','#','#','#','#','.'},
        {'#','.','#','#','.','#'}
    };
    cout << s.maxStudents(seats);
}