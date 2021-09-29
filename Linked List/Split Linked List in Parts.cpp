/*
    Company Tags      : Amazon
    Leetcode Link     : https://leetcode.com/problems/split-linked-list-in-parts/
    Frequency         : 13%
    Video Explanation : You can request for a video explanation (in Hinglish-easiest explanation) by contacting me on LinkedIn, Gmail etc. (It's FREEE)
*/

class Solution {
public:
    //Get the length of LinkedList
    int getListLength(ListNode* head) {
        int l = 0;
        while(head) {
            l++;
            head = head->next;
        }
        return l;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, NULL);
        int length = getListLength(head);
        int size   = length/k;
        int extra  = length%k;
        int i      = 0;
        
        while(head) {
            int s = size;
            result[i++] = head;
            ListNode* last = head, *prev = head;
            
            //Minimum size (MUST)
            while(s-- > 0 && last) {
                prev = last;
                last = last->next;
            }
            
            //Extra nodes
            if(extra-- > 0 && last) {
                prev = last;
                last = last->next;
            }
            
            if(prev) {
                head = prev->next;
                prev->next = NULL;
            }
        }
        
        return result;
    }
};
