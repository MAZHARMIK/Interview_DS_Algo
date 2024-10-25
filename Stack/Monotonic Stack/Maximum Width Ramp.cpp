/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=ClboFCGDT4I
    Company Tags                  : Google, Amazon
    Leetcode Link                 : https://leetcode.com/problems/maximum-width-ramp/
    Using 2-Pointer Approach Link : https://www.youtube.com/watch?v=mcJBhWXel-Y
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Using monotonic stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        stack<int> st; //stores indices of the elements

        for(int i = 0; i < n; i++) {
            if(st.empty() || nums[st.top()] >= nums[i]) {
                st.push(i);
            }
        }

        int ramp = 0;

        int j = n-1;
        while(j >= 0) {
            while(!st.empty() && nums[st.top()] <= nums[j]) { //st.top() = i
                int i = st.top();
                ramp = max(ramp, j-i);
                st.pop();
            }
            j--;
        }

        return ramp;
        
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach (Using monotonic stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;

        Stack<Integer> stack = new Stack<>(); // stores indices of elements in a decreasing order

        // Build the stack with indices of a decreasing subsequence from left to right
        for (int i = 0; i < n; i++) {
            if (stack.isEmpty() || nums[stack.peek()] >= nums[i]) {
                stack.push(i);
            }
        }

        int ramp = 0;
        int j = n - 1;

        // Traverse from the right and find the maximum width ramp
        while (j >= 0) {
            while (!stack.isEmpty() && nums[stack.peek()] <= nums[j]) {
                int i = stack.pop();
                ramp = Math.max(ramp, j - i);
            }
            j--;
        }

        return ramp;
    }
}
