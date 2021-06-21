/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/odd-even-linked-list/
*/

//Approach-1
class Solution {
public:
    ListNode *oddEvenList(ListNode * head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenTemp = head->next;
        while(even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            
            odd  = odd->next;
            even = even->next;
        }
        odd->next = evenTemp;
        return head;
    }
};


//Approach-2
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        
        ListNode* start = head;
        ListNode* end   = head;
        int count = 1;
        while(end && end->next) {
            end = end->next;
            count++;
        }
      
        count /= 2;
        
        while(count--) {
            ListNode* startNext = start->next;
            start->next = start->next->next;
            
            end->next = startNext;
            
            start = start->next;
            end = end->next;
        }
        end->next = NULL;
        
        return head;
    }
};
