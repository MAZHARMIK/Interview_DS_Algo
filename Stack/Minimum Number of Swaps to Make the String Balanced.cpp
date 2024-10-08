/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            if(ch == '[')
                st.push(ch);
            else if(!st.empty())
                st.pop();
        }
        
        return (st.size()+1)/2;
    }
};


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        
        for(char &ch : s) {
            if(ch == '[')      
              size++;
            else if(size != 0)
              size--;
        }
        
        return (size+1)/2;
    }
};




/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
import java.util.Stack;

class Solution {
    public int minSwaps(String s) {
        Stack<Character> stack = new Stack<>();

        // Traverse through the string
        for (char ch : s.toCharArray()) {
            if (ch == '[') {
                stack.push(ch); // Push opening brackets to the stack
            } else if (!stack.isEmpty()) {
                stack.pop(); // Pop a matching opening bracket for each closing bracket
            }
        }

        // The remaining elements in the stack are unmatched '[' brackets
        // The number of swaps needed is half the number of unmatched brackets
        return (stack.size() + 1) / 2;
    }
}


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minSwaps(String s) {
        int size = 0;

        // Traverse through the string
        for (char ch : s.toCharArray()) {
            if (ch == '[') {
                size++; // Increment for every '['
            } else if (size != 0) {
                size--; // Decrement if there's a '[' to balance ']'
            }
        }

        // The number of swaps needed is (size + 1) / 2
        return (size + 1) / 2;
    }
}
