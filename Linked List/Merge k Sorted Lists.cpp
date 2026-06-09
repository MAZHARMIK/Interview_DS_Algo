/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Approach-1 (Merge Sort) - https://www.youtube.com/watch?v=Q64u-W3l3mA
                                  Approach-2 (Using Heap) - 
    Company Tags                : VMWare, Amazon, Uber, Google, Twitter, LinkedIn, Airbnb, Facebook, Microsoft, IXL
    Leetcode Link               : https://leetcode.com/problems/merge-k-sorted-lists/
*/



/*********************************************************** C++ **************************************************/
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


//Approach-2 - (Using Priority Queue)
//T.C : O(N * log(K)), N =  total nodes, K = total K lists
//S.C : O(K),heap size never exceeds K
class Solution {
public:
    //T.C : O(N), N =. total nodes in all lists
    //S,C : O(N)
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto lambda = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> pq(lambda); 

        for(ListNode* node : lists) {
            if(node != NULL) {
                pq.push(node);
            }
        }

        if(pq.empty()) {
            return NULL;
        }

        ListNode* head = pq.top(); //head of final merged list
        pq.pop();

        if(head->next != NULL) {
            pq.push(head->next);
        }

        ListNode* tail = head;

        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next != NULL)
                pq.push(curr->next);
        }

        return head;

    }
};



/*********************************************************** JAVA **************************************************/
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

    public ListNode mergeTwoSortedLists(ListNode l1, ListNode l2) {

        if(l1 == null)
            return l2;

        if(l2 == null)
            return l1;

        if(l1.val <= l2.val) {
            l1.next = mergeTwoSortedLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoSortedLists(l1, l2.next);
            return l2;
        }
    }

    public ListNode partitionAndMerge(int start, int end, ListNode[] lists) {

        if(start == end)
            return lists[start];

        if(start > end)
            return null;

        int mid = start + (end-start)/2;

        ListNode l1 = partitionAndMerge(start, mid, lists);
        ListNode l2 = partitionAndMerge(mid+1, end, lists);

        return mergeTwoSortedLists(l1, l2);
    }

    public ListNode mergeKLists(ListNode[] lists) {

        int n = lists.length;

        if(n == 0)
            return null;

        return partitionAndMerge(0, n-1, lists);
    }
}


//Approach-2 - (Using Priority Queue)
//T.C : O(N * log(K)), N =  total nodes, K = total K lists
//S.C : O(K),heap size never exceeds K
class Solution {

    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            (node1, node2) -> node1.val - node2.val
        );

        for(ListNode node : lists) {
            if(node != null) {
                pq.offer(node);
            }
        }

        if(pq.isEmpty()) {
            return null;
        }

        ListNode head = pq.poll(); //head of final merged list

        if(head.next != null) {
            pq.offer(head.next);
        }

        ListNode tail = head;

        while(!pq.isEmpty()) {

            ListNode curr = pq.poll();

            tail.next = curr;
            tail = tail.next;

            if(curr.next != null) {
                pq.offer(curr.next);
            }
        }

        return head;
    }
}
