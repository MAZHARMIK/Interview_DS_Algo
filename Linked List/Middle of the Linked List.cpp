/*         Scroll down to see JAVA code also            */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=I8h_hI_BF3Y
    Company Tags                : Adobe, Amazon, Flipkart, GE, Hike, IgniteWorld, MAQ Software, Microsoft, Morgan Stanley, 
                                  Nagarro, Netskope, Payu, Qualcomm, Samsung, SAP Labs, Veritas, VMWare, Wipro, Zoho
    Leetcode Link               : https://leetcode.com/problems/middle-of-the-linked-list/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
*/


/****************************************************** C++ ******************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first  = head;
        ListNode* second = head;
        
        while(first && second && second->next) {
            first = first->next;
            second = second->next->next;
        }
        
        return first;
    }
};



/****************************************************** JAVA ******************************************************/
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode first = head;
        ListNode second = head;

        while (first != null && second != null && second.next != null) {
            first = first.next;
            second = second.next.next;
        }

        return first;
    }
}
