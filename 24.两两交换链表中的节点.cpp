#include "s.h"
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;

        ListNode *l=head,*r=head->next;
        ListNode *p = new ListNode(0, head);
        ListNode *par_head = p;
        
        while(l && r){
            
            l->next = r->next;
            r->next = l;

            p->next = r;
            p = l;

            l = l->next;
            if(l){
                
                r = l->next;
            }
                
        }
        return par_head->next;
    }
};
// @lc code=end

