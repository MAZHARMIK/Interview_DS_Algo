/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GyoRAaVCOKs
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/merge-nodes-in-between-zeros
*/

/*************************************************************** C++ ********************************************************/
//Approach-1 (Using iterative approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* P1 = head->next;
        ListNode* P2 = P1;

        while(P2 != NULL) {
            int sum = 0;
            while(P2 != NULL && P2->val != 0) {
                sum += P2->val;
                P2 = P2->next;
            }

            P1->val = sum;
            P2 = P2->next;
            P1->next = P2;
            P1 = P1->next;
        }

        return head->next;
    }
};


//Approach-2 (Using Recursive approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        if(head == NULL) {
            return head;
        }

        ListNode* temp = head;
        int sum = 0;
        while(temp != NULL && temp->val != 0) {
            sum += temp->val;
            temp = temp->next;
        }

        head->val = sum;
        head->next = mergeNodes(temp); //Recursion leap of faith
        return head;
    }
};


/*************************************************************** JAVA ********************************************************/
//Approach-1 (Using iterative approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode P1 = head.next;
        ListNode P2 = P1;
        
        while (P2 != null) {
            int sum = 0;
            while (P2 != null && P2.val != 0) {
                sum += P2.val;
                P2 = P2.next;
            }
            
            P1.val = sum;
            P2 = P2.next;
            P1.next = P2;
            P1 = P1.next;
        }
        
        return head.next;
    }
}



//Approach-2 (Using Recursive approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public ListNode mergeNodes(ListNode head) {
        head = head.next;
        if (head == null) {
            return head;
        }

        ListNode temp = head;
        int sum = 0;
        while (temp != null && temp.val != 0) {
            sum += temp.val;
            temp = temp.next;
        }

        head.val = sum;
        head.next = mergeNodes(temp); // Recursion leap of faith
        return head;
    }
}
