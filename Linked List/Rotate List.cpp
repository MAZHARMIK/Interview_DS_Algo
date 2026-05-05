/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/rotate-list
*/


/*********************************************************** C++ **************************************************/
//Approach (Straight forward)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0) 
            return head;

        //make it circular
        tail->next = head;

        //find new tail
        int steps = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        //break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Straight forward)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0)
            return head;

        int length = 1;
        ListNode tail = head;

        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        k = k % length;
        if (k == 0)
            return head;

        // make it circular
        tail.next = head;

        // find new tail
        int steps = length - k;
        ListNode newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail.next;
        }

        // break the circle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}
