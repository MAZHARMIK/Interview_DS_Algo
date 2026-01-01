/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/plus-one-linked-list/   (LEETCODE PREMIUM)
    Qn : Description
         Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
         You may assume the integer do not contain any leading zero, except the number 0 itself.
         The digits are stored such that the most significant digit is at the head of the list.
    Example :
    Input: 1 -> 2 -> 3 -> null
    Output: 1 -> 2 -> 4 -> null
    Explanation:
    123 + 1 = 124
*/

class Solution {
public:
    int addOne(ListNode* head) {
        if(!head) //if there is no node, then we make one node with value 1
            return 1;
            
        int val = head->val + addOne(head->next);
        
        head->val = val%10;
        return val/10;
    }
    ListNode * plusOne(ListNode * head) {
        int carry = addOne(head);
        
        if(carry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        
        return head;
    }
};
