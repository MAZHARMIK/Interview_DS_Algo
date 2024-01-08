/*
    MY YOUTUBE VIDEO ON THIS Qn : will come today
    Company Tags                : 24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Snapdeal, Visa
    Leetcode Link               : https://leetcode.com/problems/merge-two-sorted-lists/
*/


/************************************************ C++ ************************************************/
//T.C : O(n)
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
