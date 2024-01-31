/**                                                SCROLL BELOW TO SEE JAVA CODE ALSO                                        **/

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZhZEmGv-sOY
    Company Tags                : Google, Meta, Tokopedia
    Leetcode Link               : https://leetcode.com/problems/daily-temperatures/
*/


/******************************************************************** C++ ********************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        
        vector<int> result(n);
        
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i; //days
            }
            
            st.push(i);
        }
        
        return result;
        
    }
};



/******************************************************************** JAVA ********************************************************************/
//T.C : O(n)
//S.C :O(n)
public class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer> st = new Stack<>();
        
        int[] result = new int[n];
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && temperatures[i] >= temperatures[st.peek()]) {
                st.pop();
            }
            
            if (st.isEmpty()) {
                result[i] = 0;
            } else {
                result[i] = st.peek() - i; // days
            }
            
            st.push(i);
        }
        
        return result;
    }
}

