#include "s.h"
/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 */

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        while(ty>sy && tx>sx && tx!=ty){
            if(ty>tx){
                ty%=tx;
            }else if(tx>ty){
                tx%=ty;
            }
        }
        if(tx==sx && ty==sy){
            return true;
        }else if(tx==sx && ty>sy && (ty-sy)%tx==0){
            return true;
        }else if(ty==sy && tx>sx && (tx-sx)%ty==0){
            return true;
        }else{
            return false;
        }

    }
};
// @lc code=end

