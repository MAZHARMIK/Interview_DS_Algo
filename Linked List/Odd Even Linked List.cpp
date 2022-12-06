/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kbcucihgO_I
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/odd-even-linked-list/
*/

//Approach-1 (Time : O(n), Space : O(1))
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        
        /*
            Story : 
            1. Hume odd and even ko segregate karna hai
            2. To let's take two pointers to point to ODD and EVEN nodes
            3. Unko alag alag segregate kardenge
            4. Last me connect kardenge odd ko even se
            
        */
        
        ListNode* ODD  = head;
        ListNode* EVEN = head->next;
        
        ListNode* evenStart = head->next;
        
        while(EVEN != NULL && EVEN->next != NULL) {
            ODD->next  = EVEN->next;
            EVEN->next = EVEN->next->next; //fat sakt hai ye code
            
            ODD  = ODD->next;
            EVEN = EVEN->next;
        }
        
        ODD->next = evenStart;
        
        
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
