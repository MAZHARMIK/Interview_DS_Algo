/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=L0UnqdfFcV4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
*/


//Approach-1 (Using vector/array)
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        
        while(head) {
            vec.push_back(head->val);
            head = head->next;
        }
        
        int i = 0, j = vec.size()-1;
        int result = 0;
        
        while(i < j) {
            result = max(result, vec[i] + vec[j]);
            i++;
            j--;
        }
        
        return result;
    }
};

//Approach-2 (Using Stack)
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        
        while(curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        int count = 1;
        int N = st.size();
        int result = 0;
        
        while(count <= N/2) {
            result = max(result, curr->val + st.top());
            curr = curr->next;
            st.pop();
            count++;
        }
        
        return result;
    }
};


//Approach-3 (Reversing the second half of the linkedlist)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* mid = NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
        
        //Reversing Part
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        while(mid) {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }
        //Reversing Part
        
        ListNode* curr = head;
        int result = 0;
        while(prev) {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        
        return result;
        
    }
};
