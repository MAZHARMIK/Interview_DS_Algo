/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KEcXDqthMLE
    Company Tags                : Amazon, Flipkart, Microsoft
    Leetcode Link               : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
*/

//Approach-1 (Using a variable prev which will store node previous to slow pointer)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prevSlow  = NULL;
        ListNode* slow      = head;
        ListNode* fast      = head;
        
        while(fast && fast->next) {
            prevSlow = slow;
            slow     = slow->next;
            
            fast     = fast->next->next;
        }
        
        if(prevSlow == NULL) {
            return NULL;
        }
        
        prevSlow->next = slow->next;
        delete(slow);
        
        return head;
    }
};


//Approach-2 (Without using prev variable)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        
        ListNode* slow      = head;
        ListNode* fast      = head->next->next;
        
        while(fast && fast->next) {
            slow     = slow->next;
            
            fast     = fast->next->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete(toDelete);
        
        return head;
    }
};
