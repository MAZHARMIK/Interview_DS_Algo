/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : NA
    Leetcode Link               : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/

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
