/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tY1HevJFD98
    Company Tags                : Amazon, Google
    Leetcode Link               : https://leetcode.com/problems/split-linked-list-in-parts/
    Frequency                   : 13%
*/

//T.C : O(L+k) - You are traversing the input linkedlist only once and the array of size k only once
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
