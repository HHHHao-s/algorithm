#include "s.h"
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:

    int k;

    int partition(vector<int>& nums, int l, int r){
        int q = random_partition(nums,l,r);
        if(k == q){
            return nums[q];
        }else{
            if(q<k){
                return partition(nums,q+1,r);

            }else{
                return partition(nums,l, q-1);
            }
        }
    }

    int random_partition(vector<int>& nums, int l, int r){
        if(l==r){
            return l;
        }
        int rand = get_rand(r-l) + l;
        int mid = nums[rand];

        swap(nums[rand],nums[r]);

        int i=l-1;
        for (int j = l; j < r; j++) {
            if (nums[j] > nums[r]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;  
    }

    int get_rand(int n){
        return rand()%n;
    }

    int findKthLargest(vector<int>& nums, int target) {
        srand(time(NULL));
        k = target-1;
        return partition(nums, 0,nums.size()-1);
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> nums = {2,1};
    for(int i=0;i<100;i++){
        cout << s.findKthLargest(nums, 2) << endl;      
    }
    


    return 0;
}