#include "s.h"
/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> vis;
        
        string data;
        data.resize(6);
        int hig=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                data[hig++]=board[i][j]+'0';
            }
        }

        queue<string> q;
        q.emplace(data);
        vis.emplace(data);
        int step=0;
        vector<vector<int>> dir={
            {1,3},
            {-1,1,3},
            {-1,3},
            {-3,1},
            {-1,-3,1},
            {-1,-3}
        };
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                string s = q.front();
                q.pop();
                cout << s << ' ';
                if(s=="123450"){
                    return step;
                }
                int tmp = 1;
                int k =0;
                for(;k<6;k++){
                    if(s[k]=='0'){
                        break;
                    }
                }
                for(int j=0;j<dir[k].size();j++){
                    swap(s[k],s[k+dir[k][j]]);
                    if(!vis.count(s)){
                        vis.emplace(s);
                        q.emplace(s);
                    }
                    swap(s[k],s[k+dir[k][j]]);
                }
                
                
            }
            cout << endl;
            step++;
        }
        return -1;
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> board={
        {4,1,2},
        {5,0,3}
    };

    cout << s.slidingPuzzle(board);

    return 0; 
}