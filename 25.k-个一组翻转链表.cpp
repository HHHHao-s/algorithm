#include "s.h"
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next==NULL) return head;
        ListNode *par = new ListNode(0,head);
        ListNode *p=head,*p_next_group_head=NULL,*p_group_head=head,*pbefore=par;
        
        while(p){
            int i=0;
            for(i=0;(i<k) && p;i++){
                p=p->next;
            }
            if(i==k){ // 完整的一组
                p_next_group_head = p;
            }else{
                break;
            }
            ListNode *p_next_before = p_group_head;
            ListNode *p_next = p_group_head;
            for(i=0;(i<k);i++){
                p_next = p_next->next;
                p_group_head->next = p;
                p = p_group_head;
                p_group_head = p_next;
            }
            pbefore->next = p;
            pbefore = p_next_before;
            p = p_next_group_head;
        }
        return par->next;
    }
    
};
// @lc code=end




int main(){

    Solution sl;

    

    printList(sl.reverseKGroup(genList({1,2,3,4,5,6,7,8,9,10}),4));

    return 0;
}
