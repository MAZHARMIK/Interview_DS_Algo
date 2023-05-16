/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8yLiGS4ntHw
    Company Tags                : Moonfrog Labs, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/swap-nodes-in-pairs/
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* nextNode = head->next;
        head->next = swapPairs(head->next->next);
        nextNode->next = head;
        return nextNode;
    }
};
