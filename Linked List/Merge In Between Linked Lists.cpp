/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wIC9enD8Wzg
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/merge-in-between-linked-lists/
*/


/*************************************************************************** C++ **********************************************************/
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left  = NULL;
        ListNode* right = list1;
        
        for(int i = 0; i <= b; i++) {
            if(i == a-1) {
                left = right;
            }
            right = right->next;
        }
        
        left->next = list2;
        
        ListNode* temp = list2;
        while(temp && temp->next) {
            temp = temp->next;
        }
        
        temp->next = right;
        
        return list1;  
    }
};

/*************************************************************************** JAVA **************************************************************/
//T.C : O(m+n)
//S.C : O(1)
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode left = null;
        ListNode right = list1;
        
        for (int i = 0; i <= b; i++) {
            if (i == a - 1) {
                left = right;
            }
            right = right.next;
        }
        
        left.next = list2;
        
        ListNode temp = list2;
        while (temp != null && temp.next != null) {
            temp = temp.next;
        }
        
        temp.next = right;
        
        return list1;
    }
}
