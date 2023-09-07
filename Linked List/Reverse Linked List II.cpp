/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bRZ_Fy4zRRY
    Company Tags                : Tokopedia, Microsoft
    Leetcode Link               : https://leetcode.com/problems/reverse-linked-list-ii/
*/


//Approach-1
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        for(int i = 1; i<left; i++) {
            prev = prev->next;
        }
        
        ListNode* curr = prev->next;
        
        for(int i = 1; i<=right-left; i++) {
            
            ListNode* temp = prev->next; //0
            prev->next = curr->next; //1
            curr->next = curr->next->next; //2
            prev->next->next = temp; //3
            
        }
    
        return dummy->next;
    }
};

//Approach-2 (Not exactly one pass)
/*
We could also do it as : Reverse the nodes [left, right],
And then adjust the (left-1) node and (right+1) node
to point to the correct node.
*/
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* rightNode) {
        if(!head || !head->next || head == rightNode) {
            return head;
        }
        
        ListNode* last = reverse(head->next, rightNode);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode  = NULL;
        ListNode* leftPrev  = NULL;
        ListNode* rightNode = NULL;
        ListNode* rightNext = NULL;
        
        ListNode* curr = head;
        int c = 1;
        while(c < left) {
            leftPrev = curr;
            curr = curr->next;
            c++;
        }
        leftNode = curr;
        
        while(c < right) {
            curr = curr->next;
            c++;
        }
        
        rightNode = curr;
        rightNext = rightNode->next;
                
        // Reverse nodes [leftNode, rightNode]
        ListNode* temp = reverse(leftNode, rightNode);
        
       // Adjust the (left-1) node and (right+1) node
        if(leftPrev && leftPrev->next) {
            leftPrev->next->next = rightNext;
            leftPrev->next = temp;
        } else {
            //corner case (left  = 1)
            head->next = rightNext;
            head = temp;
        }
                        
        return head;
        
    }
};


//Approach-3 (Using Stack for One Pass Flow)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || !head->next)
            return head;
        
        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0); //to which prev points in the beginning (Example : 1 -> 2)
        dummy->next = head;
        ListNode* prev = dummy;
        
        for(int i = 1; i<=left-1; i++) {
            prev = prev->next;
        }
        
        //put [left, right] elements on stack
        ListNode* curr = prev->next;
        for(int i = left; i<= right; i++) {
            st.push(curr);
            curr = curr->next;
        }
        
        ListNode* storeRightNext = st.top()->next;
        
        //Now, link them
        while(!st.empty()) {
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }
        
        prev->next = storeRightNext;
        return dummy->next;
    }
};
