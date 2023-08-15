/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=NYZKRUT_8MY
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/partition-list/
*/

************************************************************ C++ ************************************************************
//Time : O(n), we visit each node only once
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small  = new ListNode(0);
        ListNode* large  = new ListNode(0);
        
        ListNode* smallP = small;
        ListNode* largeP = large;
        
        while(head) {
            if(head->val < x) {
                smallP->next = head;
                smallP = smallP->next;
            } else {
                largeP->next = head;
                largeP = largeP->next;
            }
            
            head = head->next;
        }
        
        largeP->next = NULL;
        smallP->next = large->next;
        return small->next;
    }
};


************************************************************ JAVA ************************************************************
//Time : O(n), we visit each node only once
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(0);
        ListNode large = new ListNode(0);
        
        ListNode smallP = small;
        ListNode largeP = large;
        
        while(head != null) {
            
            if(head.val < x) {
                smallP.next = head;
                smallP = smallP.next;
            } else {
                largeP.next = head;
                largeP = largeP.next;
            }
            
            head = head.next;
            
        }
        
        
        smallP.next = large.next;
        largeP.next = null;
        
        return small.next;
    }
}
