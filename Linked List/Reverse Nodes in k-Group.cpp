/*
    Company Tags  : Facebook, Microsoft, Tokopedia(more than once, 2020, 2021)
    Leetcode Link : https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

//Approach-1
/*
    Length of LinkedList       = length , say (L)
    number of sub linked list  = length/k (if not divisible : length/k + 1) , say (F)
    Time  : O(2*L)
    Space : O(length/k)
*/

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* rightEnd) {
        if(!head || !head->next || head == rightEnd)
            return head;
        
        ListNode* last = reverse(head->next, rightEnd);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        int length = 0;
        ListNode*   curr  = head;
        vector<ListNode*> headList;
        while(curr) {
            length++;
            curr = curr->next;
        }

        int times = length/k;
        ListNode* leftEnd = head;
        while(times--) {
            ListNode* rightEnd = leftEnd;
            for(int i = 1; i<k; i++) {
                rightEnd = rightEnd->next;
            }
            ListNode* temp = rightEnd->next;
            headList.push_back(reverse(leftEnd, rightEnd));
            leftEnd = temp;
        }
        if(leftEnd)
            headList.push_back(leftEnd);
        head = headList[0];
        curr = head;
        for(int i = 0; i<headList.size()-1; i++) {
            ListNode* temp = headList[i];
            while(temp && temp->next) {
                temp = temp->next;
            }
            temp->next = headList[i+1];
        }

        return head;
    }

};

//Approach-2 (Without using extra space . Time : O(n))
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int& k, int times) {
        if(!head || times <= 0)
            return head;
        
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int c = 1;
        
        while(curr && c <= k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        
        if(next) {
            head->next = reverse(next, k, times-1);
        }
        
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        
        int length = 0;
        ListNode* curr = head;
        while(curr) {
            length++;
            curr = curr->next;
        }
        
        return reverse(head, k, length/k);
    }

};

//Approach-3 (Using stack)
class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* curr = head;
        int length = 0;
        while(curr) {
            length++;
            curr = curr->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        
        int length = getLength(head);
        ListNode* curr = head;
        
        stack<ListNode*> st;
        int times = length/k;
        
        ListNode* prev = NULL;
        curr = head;
        while(curr) {
            if(times == 0) {
                prev->next = curr;
                break;
            }
            times--;
            int c = 1;
            while(c <= k) {
                st.push(curr);
                curr = curr->next;
                c++;
            }
            
            while(!st.empty()) {
                if(prev == NULL) {
                    prev = st.top();
                    head = prev;
                    st.pop();
                } else {
                    prev->next = st.top();
                    prev = prev->next;
                    st.pop();
                }
            }
            
        }
        
        if(curr == NULL) //means length==k and prev needs to be pointed to NULL
            prev->next = NULL;
        
        return head;
    }

};
