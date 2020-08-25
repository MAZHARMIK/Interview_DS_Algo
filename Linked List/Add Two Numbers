/*
    Company Tags     : Accolite, Amazon, Flipkart, MakeMyTrip, Microsoft, Qualcomm, Snapdeal
    Leetcode Qn Link : https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(l1 || l2) {
            sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
            carry = (sum>=10)?1:0;
            int digit  = sum%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL) {
                head = temp;
                prev = head;
            } else {
                prev->next = temp;
            }
            prev = temp;
            
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        if(carry == 1) {
            ListNode* temp = new ListNode(1);
            prev->next = temp;
        }
        return head;
    }
};
