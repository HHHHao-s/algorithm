#include "../s.h"

class Solution {
private:
    int doone(vector<int>& nums1, vector<int>& nums2, int d, int d2, unordered_map<int,int>&s1, unordered_map<int,int>&s2){

        for(auto [num, cnt]:s1){
            if(s2.count(num)){
                d2+= s2[num];
                s2.erase(num);
            }
        }

        if(d2>=nums2.size()/2){
            return s1.size() + s2.size();
        }else{
            return s1.size() + s2.size() - (nums2.size()/2-d2);
        }
        return -1;

    }

public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> s1, s2;
        for(int num: nums1){
            s1[num]++;
        }
        for(int num:nums2){
            s2[num]++;
        }
        int d = 0;
        for(auto [num, cnt]: s1){
            s1[num]=1;
            d+=cnt-1;
            // if(d>=nums1.size()/2){
            //     break;
            // }
        }
        int d2= 0;

        for(auto [num, cnt]: s2){
            s2[num]=1;
            d2+=cnt-1;
            // if(d2>=nums2.size()/2){
            //     break;
            // }
        }

        if(d>=nums1.size()/2 && d2>=nums2.size()/2){
            for(auto [num, cnt]:s2){
                if(s1.count(num)){
                    s1.erase(num);
                    
                }
            }
            return s1.size()+s2.size();
        }else{
            
            if(d>=nums1.size()/2 && d2<nums2.size()/2){
                return doone(nums1, nums2, d, d2, s1,s2);
                

            }else if(d2>=nums2.size()/2 && d<nums1.size()/2){
                return doone(nums2, nums1, d2,d, s2,s1);
            }else if(d2<nums2.size()/2 && d<nums1.size()/2){
                int both = 0;
                for(auto [num, cnt]: s1){
                    if(s2.count(num)){
                        if(d2<nums2.size()/2){
                            d2++;
                            s2.erase(num);
                        }else{
                            break;
                        }

                        

                    }
                }
                if(d2==nums2.size()/2){
                    for(auto [num, cnt]:s2){
                        if(s1.count(num)){
                            d++;
                            s1.erase(num);
                            
                        }
                    }
                    if(d>=nums1.size()/2){
                        return s1.size()+s2.size();
                    }else{
                        return s1.size()-(nums1.size()/2-d)+ s2.size();
                    }

                }else{
                    return s1.size() - (nums1.size()/2-d) + s2.size() - (nums2.size()/2-d2);  
                }

                


            }
        }
        return 0;



        
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2,4,1,4},
    nums2={2,4,10,10};
    cout << s.maximumSetSize(nums1, nums2);
}