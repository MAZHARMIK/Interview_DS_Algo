/*                         Scroll below to see JAVA code also                 */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RreHsOfi14w
    Company Tags                : 24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Snapdeal, Visa
    Leetcode Link               : https://leetcode.com/problems/merge-two-sorted-lists/
*/


/************************************************ C++ ************************************************/
//Approach-1 (Recursion)
//T.C : O(m+n) - total number of nodes
//S.C : O(1) (ignoring recursive stack space)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* result;
        if(l1->val < l2->val) {
            result = l1;
            result->next = mergeTwoLists(result->next, l2);
        } else {
            result = l2;
            result->next = mergeTwoLists(l1, result->next);
        }
        return result;
    }
};


//Approach-2 (Iterative)
//T.C : O(m+n) - total number of nodes
//S.C : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        
        while(head1 && head2){
            if(head1->val > head2->val){
                temp->next = head2;
                head2 = head2->next;
            } else {
                temp->next = head1;
                head1 = head1->next;
            }
            temp = temp->next;
        }
        if(head1 == NULL)
            temp->next = head2;
        else
            temp->next = head1;
        return head->next;
    }
};

/************************************************ JAVA ************************************************/
//T.C : O(n)
//S.C : O(1) (ignoring recursive stack space)
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        
        ListNode result;
        if (l1.val < l2.val) {
            result = l1;
            result.next = mergeTwoLists(l1.next, l2);
        } else {
            result = l2;
            result.next = mergeTwoLists(l1, l2.next);
        }
        return result;
    }
}


//Approach-2 (Iterative)
//T.C : O(m+n) - total number of nodes
//S.C : O(1)
class Solution {
    public ListNode mergeTwoLists(ListNode head1, ListNode head2) {
        if (head1 == null)
            return head2;
        if (head2 == null)
            return head1;

        ListNode head = new ListNode(-1);
        ListNode temp = head;

        while (head1 != null && head2 != null) {
            if (head1.val > head2.val) {
                temp.next = head2;
                head2 = head2.next;
            } else {
                temp.next = head1;
                head1 = head1.next;
            }
            temp = temp.next;
        }

        if (head1 == null)
            temp.next = head2;
        else
            temp.next = head1;

        return head.next;
    }
}
