/*
      MY YOUTUBE VIDEO ON THIS Qn : <soon>
      Company Tags                : Paytm, VMWare, Zoho, Accolite, Amazon, Microsoft, Samsung, Snapdeal, D-E-Shaw, MakeMyTrip, Teradata, Walmart, 
                                    Goldman Sachs, Intuit, Adobe, SAP Labs, Tejas Network, Cisco, Qualcomm, Cognizant, Mahindra Comviva, IgniteWorld
      Leetcode Link               : https://leetcode.com/problems/reverse-linked-list/
      GfG Link                    : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
*/

//Approach-1 (Using Recursion - I)
class Solution {
public:
    
    ListNode* reverseSolve(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* last   = reverseSolve(head->next);
        head->next->next = head;
        head->next       = NULL;
            
        return last;
        
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseSolve(head);
    }
};


//Approach-2 (Using Recursio - II)
class Solution {
public:
    
    ListNode* reverseHelp(ListNode* head, ListNode* prev) {
        
        if(!head)
            return prev;
        
        ListNode* temp = head->next;
        head->next = prev;
        
        return reverseHelp(temp, head);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseHelp(head, NULL);
    }
};


//Approach-3 (Iterative)
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
