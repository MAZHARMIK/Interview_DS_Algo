/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=B-uQN5wp6Jg
    Company Tags                : Accolite, Amazon, Flipkart, MakeMyTrip, Microsoft, Qualcomm, Snapdeal
    Leetcode Link               : https://leetcode.com/problems/add-two-numbers-ii/   
*/

//Approach-1 (Reverse the LinkedList)
class Solution {
public:
    
    ListNode* reverseLL(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};


//Approach-2 (Using Stack) - What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};
