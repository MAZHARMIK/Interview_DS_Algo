/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/insertion-sort-list/
    GfG Link                    : https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1
*/

/**************************************************************** C++ ****************************************************************/
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = new ListNode(-1);
        ListNode* curr    = head;
        while(curr) {
            ListNode* prev    = newHead;
            ListNode* nxt     = newHead->next;
            while(nxt) {
                if(curr->val < nxt->val)
                    break;
                prev = nxt;
                nxt = nxt->next;
            }
            
            //Simple example to understand the steps below :
            //Think about [1 , 2 , 4, 3]
            //curr = 3
            //nxt  = 4
            //prev = 2
            ListNode* temp = curr->next; //storing for curr next iteration
            curr->next     = nxt;   //3->4
            prev->next     = curr;  //2->3
            curr = temp;
        }
        return newHead->next;
    }
};


/**************************************************************** JAVA ****************************************************************/
//T.C : O(n^2)
//S.C : O(1)
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode newHead = new ListNode(-1);
        ListNode curr = head;

        while (curr != null) {
            ListNode prev = newHead;
            ListNode nxt = newHead.next;

            while (nxt != null) {
                if (curr.val < nxt.val)
                    break;
                prev = nxt;
                nxt = nxt.next;
            }

            ListNode temp = curr.next;  // storing for curr's next iteration
            curr.next = nxt;            // inserting curr in the sorted part
            prev.next = curr;           // adjusting the links

            curr = temp;  // moving to the next node for the next iteration
        }

        return newHead.next;
    }   
}
