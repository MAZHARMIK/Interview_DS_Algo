/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tY1HevJFD98
    Company Tags                : Amazon, Google
    Leetcode Link               : https://leetcode.com/problems/split-linked-list-in-parts/
    Frequency                   : 13%
*/


/****************************************************** C++ ******************************************************/
//T.C : O(L+k) - You are traversing the input linkedlist only once and the array of size k only once
//S.C : O(1) (Not including result vector)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L = 0;
        while(curr) {
            L++;
            curr = curr->next;
        }
        
        int eachBucketNodes = L/k; //0
        int remainderNodes  = L%k; //3
        
        vector<ListNode*> result(k, NULL);
        curr           = head;
        ListNode* prev = NULL;
        
        for(int i = 0; curr && i < k ; i++) {
            
            result[i] = curr;
            
            for(int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = NULL;
            remainderNodes--;
        }
        
        return result;
    }
};


/****************************************************** JAVA ******************************************************/
//T.C : O(L+k) - You are traversing the input linkedlist only once and the array of size k only once
//S.C : O(1) (Not including result vector)
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        // Step 1: Find the length of the list
        ListNode curr = head;
        int L = 0;
        while (curr != null) {
            L++;
            curr = curr.next;
        }
        
        // Step 2: Calculate the base size of each part and the remainder
        int eachBucketNodes = L / k;
        int remainderNodes = L % k;
        
        // Step 3: Create an array to hold the resulting ListNode parts
        ListNode[] result = new ListNode[k];
        
        // Step 4: Reinitialize `curr` to the head of the list
        curr = head;
        ListNode prev = null;
        
        // Step 5: Loop over k parts
        for (int i = 0; curr != null && i < k; i++) {
            result[i] = curr;
            
            // Step 6: Loop over the nodes in the current part
            for (int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr.next;
            }
            
            // Step 7: Break the connection after the current part
            if (prev != null) {
                prev.next = null;
            }
            
            // Step 8: Decrease the remainder count
            remainderNodes--;
        }
        
        return result;
    }
}
