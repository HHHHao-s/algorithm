#include "s.h"
/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        while(p2!=nullptr){
            int a = gcd(p1->val, p2->val);
            ListNode *nw = new ListNode(a, p2);
            p1->next = nw;
            p1 = p2;
            p2 = p2->next;

            
        }
        return head;

    }
};
// @lc code=end

