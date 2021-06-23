/*
    Company Tags  : Not known yet (Let me know if you get it :-) )
    Leetcode Link : https://leetcode.com/problems/reverse-linked-list-ii/
*/

//Approach-1 (Not exactly one pass)
/*
We could also do it as : Reverse the nodes [left, right],
And then adjust the (left-1) node and (right+1) node
to point to the correct node.
*/
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* rightNode) {
        if(!head || !head->next || head == rightNode) {
            return head;
        }
        
        ListNode* last = reverse(head->next, rightNode);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode  = NULL;
        ListNode* leftPrev  = NULL;
        ListNode* rightNode = NULL;
        ListNode* rightNext = NULL;
        
        ListNode* curr = head;
        int c = 1;
        while(c < left) {
            leftPrev = curr;
            curr = curr->next;
            c++;
        }
        leftNode = curr;
        
        while(c < right) {
            curr = curr->next;
            c++;
        }
        
        rightNode = curr;
        rightNext = rightNode->next;
                
        // Reverse nodes [leftNode, rightNode]
        ListNode* temp = reverse(leftNode, rightNode);
        
       // Adjust the (left-1) node and (right+1) node
        if(leftPrev && leftPrev->next) {
            leftPrev->next->next = rightNext;
            leftPrev->next = temp;
        } else {
            //corner case (left  = 1)
            head->next = rightNext;
            head = temp;
        }
                        
        return head;
        
    }
};
