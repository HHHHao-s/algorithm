#include "s.h"
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * pslow = head, *pfast = head;

        while(pslow!=NULL && pfast!=NULL){
            pslow = pslow->next;
            if(pfast->next != NULL)
                pfast = pfast->next->next;
            else
                return NULL;

            if(pfast && pslow && pfast == pslow) break;
        }


        if(pfast && pfast==pslow){
            
            ListNode *p = head;
            while(p!=pslow){
                p=p->next;
                pslow=pslow->next;   
            }

            return p;


        }
        else return NULL;
        
    }
};
// @lc code=end

