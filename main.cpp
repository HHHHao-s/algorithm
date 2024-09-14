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



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定的5张牌是否是顺子
     * @param nums int整型vector 扑克牌对应的数字集合
     * @return bool布尔型
     */
    bool isStraight(vector<int>& nums) {
        // write code here
        int ghost= 0;
        int a = 0;
        vector<int> each(15);


        for(int i=0;i<nums.size();i++){
            ghost += nums[i]==0;
            each[nums[i]]=1;
        }
       
        for(int i=2;i<=10;i++){
            
            if(each[i]==1){
                int cnt= 0;
                for(int j=i;j<=i+4;j++){
                    if(j==14){
                        if(each[1]){
                            cnt++;
                        }
                        break;
                    }
                    if(each[j]){
                        cnt++;
                    }

                }
                if(cnt + ghost==5){
                    return true;
                }
                break;

            }
        }
        if(each[1]==1){
            int cnt= 0;
            for(int j=1;j<=5;j++){
                cnt+= each[j];

            }
            if(cnt + ghost==5){
                return true;
            }
        }
       
        return false;


    }
};


