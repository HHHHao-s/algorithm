#include "s.h"
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        
        ListNode * pslow = head, *pfast = head;

        while(pslow!=NULL && pfast!=NULL){
            pslow = pslow->next;
            if(pfast->next != NULL)
                pfast = pfast->next->next;
            else
                return false;

            if(pfast && pslow && pfast == pslow) return true;
        }

        if(pfast && pfast==pslow) return true;
        else return false;
    }
};
// @lc code=end

