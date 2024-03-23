/*            Scroll down to see JAVA code also             */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7cp_HR1BT1E
      Company Tags                : Amazon, Microsoft, OYO
      Leetcode Link               : https://leetcode.com/problems/reorder-list/
*/


/********************************************************************* C++ *****************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;
        while(curr) {
            st.push(curr);
            curr = curr->next;
        }
        
        int k = st.size()/2;
        curr = head;
        while(k--) {
            ListNode* topNode = st.top();
            st.pop();
            
            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }
        
        curr->next = NULL;
    }
};

//Approach-2 (without stack)
//T.C : O(n)
//S.C : O(1) AUxiliary, O(n) Recursion stack space
class Solution {
public:
    ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revHalf = reverseLL(slow);
        
        ListNode* curr = head;
        while(revHalf->next) {
            ListNode* tempFront = curr->next;
            curr->next          = revHalf;
            
            ListNode* tempBack  = revHalf->next;
            revHalf->next       = tempFront;
            
            revHalf             = tempBack;
            curr                = tempFront;
        }
    }
};


//Approach-3 (Only Recursion)
//T.C : O(n)
//S.C : O(1) AUxiliary SPace and O(n) Recursion Stack Space
class Solution {
public:
    ListNode* curr;
    
    void solve(ListNode* head) {
        if(!head) {
            return;
        }
        
        solve(head->next);
        ListNode* tempn = curr->next;
        if(tempn == NULL) {
            return;
        } else if(head == curr) {
            head->next = NULL;
            return;
        }
        
        curr->next = head;
        head->next = tempn == head ? NULL : tempn;
        
        curr = tempn;
    }
    
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};


/********************************************************************* JAVA *****************************************************************/
// Approach-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
public class Solution {
    public void reorderList(ListNode head) {
        Stack<ListNode> stack = new Stack<>();

        ListNode curr = head;
        while (curr != null) {
            stack.push(curr);
            curr = curr.next;
        }

        int k = stack.size() / 2;
        curr = head;
        while (k-- > 0) {
            ListNode topNode = stack.pop();

            ListNode temp = curr.next;
            curr.next = topNode;
            topNode.next = temp;
            curr = temp;
        }

        if (curr != null)
            curr.next = null;
    }
}


// Approach-2 (without stack)
// T.C : O(n)
// S.C : O(1) Auxiliary, O(n) Recursion stack space
class Solution {
    ListNode reverseLL(ListNode node) {
        if (node == null || node.next == null)
            return node;
        ListNode last = reverseLL(node.next);
        node.next.next = node;
        node.next = null;
        return last;
    }

    void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null)
            return;

        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode revHalf = reverseLL(slow);

        ListNode curr = head;
        while (revHalf.next != null) {
            ListNode tempFront = curr.next;
            curr.next = revHalf;

            ListNode tempBack = revHalf.next;
            revHalf.next = tempFront;

            revHalf = tempBack;
            curr = tempFront;
        }
    }
}


// Approach-3 (Only Recursion)
// T.C : O(n)
// S.C : O(1) Auxiliary Space and O(n) Recursion Stack Space
class Solution {
    ListNode curr;

    void solve(ListNode head) {
        if (head == null) {
            return;
        }

        solve(head.next);
        ListNode tempn = curr.next;
        if (tempn == null) {
            return;
        } else if (head == curr) {
            head.next = null;
            return;
        }

        curr.next = head;
        head.next = tempn == head ? null : tempn;

        curr = tempn;
    }

    void reorderList(ListNode head) {
        curr = head;
        solve(head);
    }
}
