/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9vC4I5sKFsw
    Company Tags  : GOOGLE
    Leetcode Link : https://leetcode.com/problems/linked-list-random-node/
*/

//Approach-1 (Simple) - (O(n) time and space)
class Solution {
public:
    vector<int> arr; //O(N) space
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n       = arr.size();
        int r_index = rand()%n;
        return arr[r_index]; //O(1) access time
    }
};

//Better Approach (Using Reservior Sampling) - Timr : O(n)
class Solution {
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        ListNode* curr = temp;
        int size = 1;
        while(curr) {
            //choosing probability is 1/size (reservior sampling)
            if(rand()%size == 0)
                res = curr->val;
            curr = curr->next;
            size++;
        }
        return res;
    }
};
