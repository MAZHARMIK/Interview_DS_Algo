/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KlB72wJDTv4
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
    Similar Problem             : https://www.youtube.com/watch?v=B-uQN5wp6Jg (Add Two Numbers II - Leetcode 445)
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Using Reverse of LinkedList)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return last;
        
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        int carry = 0;
        
        while(curr != NULL) {
            
            int newValue = curr->val * 2 + carry;
            curr->val = newValue%10;
            
            if(newValue >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            
            prev = curr;
            curr = curr->next;
            
        }
        
        if(carry != 0) {
            ListNode* newHead = new ListNode(carry);
            prev->next = newHead;
        }
        
        
        return reverseList(head);
    }
};


//Approach-2 (Using Recursion)
//T.C : O(n)
//S.C : O(n) system stack space
class Solution {
public:
    
    int doubleUtil(ListNode* head) {
        if(head == NULL)
            return 0;
        
        
        int carry  = doubleUtil(head->next);
        int newVal = (head->val)*2 + carry;
        head->val = newVal%10;
        
        
        return newVal/10;
        
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        int lastCarry = doubleUtil(head);
        
        if(lastCarry > 0) {
            ListNode* newHead = new ListNode(lastCarry);
            newHead->next = head;
            return newHead;
        }
        
        return head;
        
    }
};


//Approach-3 (Using prev and curr left to right traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL) {
            
            int newVal = curr->val * 2;
            
            if(newVal < 10) {
                curr->val = newVal;
            } else if(prev != NULL) {
                curr->val = newVal%10;
                
                prev->val += 1;
            } else { //prev is NULL means we are standing at head node
                ListNode* newHead = new ListNode(1);
                newHead->next = curr;
                curr->val = newVal%10;
                head = newHead;
            }
            
            prev = curr;
            curr = curr->next;
            
        }
        
        
        return head;
    }
};


//Approach-4 (Using one pointer left to right traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        
        if(head->val >= 5) {
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
            //head = new ListNode(0, head);
        }
        
        
        ListNode* curr = head;
        
        while(curr != NULL) {
            
            curr->val = (curr->val * 2)%10;
            
            
            if(curr->next != NULL && curr->next->val >= 5) {
                curr->val += 1;
            }
            
            curr = curr->next;
            
        }
        
        
        return head;
    }
};


/*************************************************************** JAVA ******************************************************/
// Approach-1 (Using Reverse of LinkedList)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode last = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        
        return last;
    }
    
    public ListNode doubleIt(ListNode head) {
        head = reverseList(head);
        
        ListNode curr = head;
        ListNode prev = null;
        int carry = 0;
        
        while (curr != null) {
            int newValue = curr.val * 2 + carry;
            curr.val = newValue % 10;
            
            if (newValue >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            
            prev = curr;
            curr = curr.next;
        }
        
        if (carry != 0) {
            ListNode newHead = new ListNode(carry);
            prev.next = newHead;
        }
        
        return reverseList(head);
    }
}

// Approach-2 (Using Recursion)
// T.C : O(n)
// S.C : O(n) system stack space
class Solution {
    public int doubleUtil(ListNode head) {
        if (head == null)
            return 0;
        
        int carry = doubleUtil(head.next);
        int newVal = (head.val) * 2 + carry;
        head.val = newVal % 10;
        
        return newVal / 10;
    }
    
    public ListNode doubleIt(ListNode head) {
        int lastCarry = doubleUtil(head);
        
        if (lastCarry > 0) {
            ListNode newHead = new ListNode(lastCarry);
            newHead.next = head;
            return newHead;
        }
        
        return head;
    }
}

// Approach-3 (Using prev and curr left to right traversal)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public ListNode doubleIt(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        
        while (curr != null) {
            int newVal = curr.val * 2;
            
            if (newVal < 10) {
                curr.val = newVal;
            } else if (prev != null) {
                curr.val = newVal % 10;
                prev.val += 1;
            } else {
                ListNode newHead = new ListNode(1);
                newHead.next = curr;
                curr.val = newVal % 10;
                head = newHead;
            }
            
            prev = curr;
            curr = curr.next;
        }
        
        return head;
    }
}

// Approach-4 (Using one pointer left to right traversal)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public ListNode doubleIt(ListNode head) {
        if (head.val >= 5) {
            ListNode newHead = new ListNode(0);
            newHead.next = head;
            head = newHead;
        }
        
        ListNode curr = head;
        
        while (curr != null) {
            curr.val = (curr.val * 2) % 10;
            
            if (curr.next != null && curr.next.val >= 5) {
                curr.val += 1;
            }
            
            curr = curr.next;
        }
        
        return head;
    }
}
