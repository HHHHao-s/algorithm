#include "s.h"
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mymerge(vector<ListNode*>& lists,int begin, int end){
        if(lists.empty()) return NULL;

        if(end-begin==1){
            return lists[begin];
        }else{
            if(end-begin==2){
                ListNode *p1=lists[begin],*p2= lists[begin+1];
                if(p1==NULL) return p2;
                else if(p2==NULL) return p1;
                ListNode par =  {0,NULL};
                if(p1->val>p2->val) {
                    par.next = p2;
                    p2=p2->next;
                }else{
                    par.next = p1;
                    p1=p1->next;
                }
                ListNode *p = par.next;
                while(p1&&p2){
                    if(p1->val>p2->val) {
                        ListNode * tmp = p2->next;
                        p->next = p2;
                        p2=tmp;
                    }else{
                        ListNode *tmp  = p1->next;
                        p->next = p1;
                        p1=tmp;
                    }
                    p = p->next;
                }

                if(p1){
                    p->next= p1;
                }else{
                    p->next = p2;
                }
                return par.next;
            }else{
                
                vector<ListNode*> merged= {mymerge(lists,begin,begin+(end-begin)/2),mymerge(lists,begin+(end-begin)/2,end)};
                return mymerge(merged,0,2);
            }
        }
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        return mymerge(lists,0,lists.size());
    }

    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.empty()) return NULL;

        

    //     if(lists.size()==1){
    //         return lists[0];
    //     }else{
    //         if(lists.size()==2){
    //             ListNode *p1=lists[0],*p2= lists[1];
    //             if(p1==NULL) return p2;
    //             else if(p2==NULL) return p1;
    //             ListNode par =  {0,NULL};
    //             if(p1->val>p2->val) {
    //                 par.next = p2;
    //                 p2=p2->next;
    //             }else{
    //                 par.next = p1;
    //                 p1=p1->next;
    //             }
    //             ListNode *p = par.next;
    //             while(p1&&p2){
    //                 if(p1->val>p2->val) {
    //                     ListNode * tmp = p2->next;
    //                     p->next = p2;
    //                     p2=tmp;
    //                 }else{
    //                     ListNode *tmp  = p1->next;
    //                     p->next = p1;
    //                     p1=tmp;
    //                 }
    //                 p = p->next;
    //             }

    //             if(p1){
    //                 p->next= p1;
    //             }else{
    //                 p->next = p2;
    //             }
    //             return par.next;
    //         }else{
    //             vector<ListNode*> v1,v2;
    //             int acc=0;
    //             for(auto it: lists){
    //                 if(acc>lists.size()/2){
    //                     v2.push_back(it);
    //                 }else{
    //                     v1.push_back(it);
    //                 }
    //                 acc++;
    //             }
    //             vector<ListNode*> merged= {mergeKLists(v1),mergeKLists(v2)};
    //             return mergeKLists(merged);
    //         }
    //     }
    // }
};
// @lc code=end

int main(){


    vector<ListNode*> lists= {genList({1,4,5,5,5,5,5,}), genList({1,3,4}), genList({2,6})};
    // vector<ListNode*> list1= {};
    // vector<ListNode*> list2= {genList({1,4,5}), genList({1,3,4}), genList({2,6})};
    
    Solution sl;
    printList(sl.mergeKLists(lists));
    // printList(sl.mergeKLists(list1));
    return 0;
}