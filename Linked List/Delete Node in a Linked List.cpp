/*         Scroll Down to see JAVA code also      */
/*
    MY YOUTUBE VIDEON ON THIS Qn : https://www.youtube.com/watch?v=TvLWOECe8mQ
    Company Tags                 : Apple, Adobe, Microsoft, Samsung
    Leetcode Link                : https://leetcode.com/problems/delete-node-in-a-linked-list/
    Similar GfG Link             : https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
*/

/**************************************** C++ *****************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        
        while(node && node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        delete(node);
        prev->next = NULL;
    }
};


/**************************************** JAVA *****************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public void deleteNode(ListNode node) {
        ListNode prev = null;

        while (node != null && node.next != null) {
            node.val = node.next.val;
            prev = node;
            node = node.next;
        }
        
        if (node != null) {
            if (prev != null)
                prev.next = null;
            else
                node = null;
        }
    }
}
