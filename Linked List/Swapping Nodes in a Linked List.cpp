/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TxryJMerDwE
    Company Tags                : Microsoft, Amazon
    Leetcode Link               : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
*/

//Approach-1 (Making use of length of LinkedList)
class Solution {
public:
    
    int FindLength(ListNode* head) {
        int l = 0;
        
        while(head) {
            head = head->next;
            l++;
        }
        return l;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        //Kth Node from Start
        //Kth Node from End = Length-K+1 Node from Beginning
        
        int Length = FindLength(head);
        
        int k_1 = k;
        ListNode* temp1 = head;
        while(k_1 > 1) {
            temp1 = temp1->next;
            k_1--;
        }
        
        int k_2 = Length-k+1;
        ListNode* temp2 = head;
        while(k_2 > 1) {
            temp2 = temp2->next;
            k_2--;
        }
        
        swap(temp1->val, temp2->val);
        return head;
        
    }
};


//Approach-2 (Using only One Pass)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        
        ListNode* temp = head;
        
        while(temp) {
            
            if(p2 != NULL)
                p2 = p2->next;
                
            
            k--;
            if(k == 0) {
                p1 = temp;
                p2 = head;
            }
            
            
            temp = temp->next;
            
        }
        
        swap(p1->val, p2->val);
        return head;
    }
};
