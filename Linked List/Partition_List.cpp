/*
    Company Tags  : Microsoft
    Leetcode Link : https://leetcode.com/problems/partition-list/
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(-1);
        ListNode* afterHead  = new ListNode(-1);
        
        ListNode* beforeTemp = beforeHead;
        ListNode* afterTemp  = afterHead;
        
        while(head) {
            if(head->val < x) {
                beforeTemp->next = head;
                beforeTemp = beforeTemp->next;
            } else {
                afterTemp->next = head;
                afterTemp = afterTemp->next;
            }
            head = head->next;
        }
        afterTemp->next = NULL;
        beforeTemp->next = afterHead->next;
        return beforeHead->next;
    }
};
