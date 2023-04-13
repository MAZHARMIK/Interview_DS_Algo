/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HEh7EtNSXtg
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/validate-stack-sequences/
*/


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int n = pushed.size();
        
        int i = 0, j = 0;
        
        while(i < n && j < n) {
            
            st.push(pushed[i]);
            
            while(!st.empty() && j < n && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
            
        }
        
        return st.empty();
    }
};
