/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q64u-W3l3mA
    Company Tags                : VMWare, Amazon, Uber, Google, Twitter, LinkedIn, Airbnb, Facebook, Microsoft, IXL
    Leetcode Link               : https://leetcode.com/problems/merge-k-sorted-lists/
*/


//Approach-1 (Using merge sort) - Time : O(log(k) * k * n)
/*
    Where k = total number of lists
    and n = average length of every linkedlist
    Why ?
    Because, The merge in the higher layer has more nodes, 
    the lists are longer than the lists in the bottoms. 
    But the number of operation of merge is the same in every level(which is k*n). 
    and log(k) comes from "partitionAndMerge" function. We will have log(k) levels and on each level we do a merge.
*/
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if(l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        
        return NULL;
    }
    
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if(start == end)
            return lists[start];
        
        if(start > end)
            return NULL;
        
        int mid = start + (end-start)/2;
        
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);
        
        return mergeTwoSortedLists(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        return partitionAndMerge(0, n-1, lists);
        
    }
};


//Approach-2 - (Using Priority Queue) -> SOON
