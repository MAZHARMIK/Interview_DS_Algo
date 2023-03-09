/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vlrxs-LPni4
    Company Tags  : Microsoft, Paytm, VMWare, Accolite, Amazon, OYO Rooms, Samsung
                    Snapdeal, D-E-Shaw, Hike, MakeMyTrip, Walmart, MAQ Software, Adobe, SAP Labs, 
                    Qualcomm, Veritas
    Leetcode Link : https://leetcode.com/problems/linked-list-cycle-ii/
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next))
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        if(fast != slow)
            return NULL;
        
        ListNode* entry = head;
        while(entry != slow) {
            entry = entry->next;
            slow  = slow->next;
        }
        return entry;
    }
};
