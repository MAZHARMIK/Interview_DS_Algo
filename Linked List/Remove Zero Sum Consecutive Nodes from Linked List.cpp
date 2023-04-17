/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5UWEVMg10rY
    Company Tags                : NA
    Leetcode Link               : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*> mp;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        
        
        
        while(head) {
            prefixSum += head->val;
            
            if(mp.find(prefixSum) != mp.end()) {
                
                ListNode* P     = mp[prefixSum];
                ListNode* start = P;
                int pSum        = prefixSum;
                
                while(start != head) {
                    
                    start = start->next;
                    pSum += start->val;
                    if(start != head)
                        mp.erase(pSum);
                }
                
                P->next = start->next;
                
            } else {
                mp[prefixSum] = head;
            }
            
            head = head->next;
        }
        
        return dummy->next;
    }
};
