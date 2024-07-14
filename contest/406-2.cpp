#include "../s.h"

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode *dummy = new ListNode(1);
        dummy->next = head;
        
        unordered_set<int> nm;
        for(auto i : nums){
            nm.insert(i);
        }
        ListNode *last = dummy;
        for(ListNode*p=head;p!=nullptr;p=p->next){
            if(nm.count(p->val)){
                last->next = p->next;
            }else{
                last = p;
            }
        }

        return dummy->next;
        


    }
};