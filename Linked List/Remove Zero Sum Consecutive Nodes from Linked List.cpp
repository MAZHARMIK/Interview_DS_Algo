/*     Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5UWEVMg10rY
    Company Tags                : NA
    Leetcode Link               : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/


/******************************************************************** C++ ********************************************************************/
//T.C : O(n^2)
//S.C : O(n) - We took a map
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*> mp;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        
        
        
        while(head) {
            prefixSum += head->val;
            
            if(mp.find(prefixSum) != mp.end()) {
                
                ListNode* P     = mp[prefixSum];
                ListNode* start = P;
                int pSum        = prefixSum;
                
                while(start != head) {
                    
                    start = start->next;
                    pSum += start->val;
                    if(start != head)
                        mp.erase(pSum);
                }
                
                P->next = start->next;
                
            } else {
                mp[prefixSum] = head;
            }
            
            head = head->next;
        }
        
        return dummy->next;
    }
};



/******************************************************************** JAVA ********************************************************************/
//T.C : O(n^2)
//S.C : O(n) - We took a map
public class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        int prefixSum = 0;
        Map<Integer, ListNode> map = new HashMap<>();
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        map.put(0, dummy);
        
        while (head != null) {
            prefixSum += head.val;
            
            if (map.containsKey(prefixSum)) {
                ListNode p = map.get(prefixSum);
                ListNode start = p;
                int pSum = prefixSum;
                
                while (start != head) {
                    start = start.next;
                    pSum += start.val;
                    if (start != head) {
                        map.remove(pSum);
                    }
                }
                
                p.next = start.next;
                
            } else {
                map.put(prefixSum, head);
            }
            
            head = head.next;
        }
        
        return dummy.next;
    }
}
