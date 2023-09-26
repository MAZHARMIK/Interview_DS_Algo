/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/remove-duplicate-letters/
      EXACT SAME LEETCODE Qn      : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/

/*
    NOTE : In this Qn, I have used the result string which is working just like a stack.
    We push into it, we pop from it from the back (result.pop_back()). So this Qn also falls under stack category.
    You can also solve it using stack.
*/

/********************************************* C++ *********************************************/
//Approach-1 (Using string as a stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(1)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string result;
        
        vector<bool> taken(26, false); //O(1) space
        vector<int> lastIndex(26); //O(1) space
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if(taken[idx] == true) continue;
            
            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(s[i]);
            taken[idx] = true;
            
        }
        
        return result;
    }
};

//Approach-2 (Using stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(n) stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;
        
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if(taken[idx] == true) continue;
            
            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            taken[idx] = true;
            
        }
        
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        
        return result;
    }
};


/********************************************* JAVA *********************************************/
//Using string as a stack
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(1)
public class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        StringBuilder result = new StringBuilder();
        
        boolean[] taken = new boolean[26];
        int[] lastIndex = new int[26];
        Arrays.fill(lastIndex, -1);
        
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            lastIndex[ch - 'a'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            int idx = ch - 'a';
            
            if (taken[idx]) continue;
            
            while (result.length() > 0 && ch < result.charAt(result.length() - 1) && lastIndex[result.charAt(result.length() - 1) - 'a'] > i) {
                taken[result.charAt(result.length() - 1) - 'a'] = false;
                result.deleteCharAt(result.length() - 1);
            }
            
            result.append(ch);
            taken[idx] = true;
        }
        
        return result.toString();
    }
}


//Approach-2 (Using stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(n) stack
public class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        
        boolean[] taken = new boolean[26];
        int[] lastIndex = new int[26];
        
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            lastIndex[ch - 'a'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            
            if (taken[idx]) continue;
            
            while (!st.isEmpty() && s.charAt(i) < st.peek() && lastIndex[st.peek() - 'a'] > i) {
                taken[st.pop() - 'a'] = false;
            }
            
            st.push(s.charAt(i));
            taken[idx] = true;
        }
        
        StringBuilder result = new StringBuilder();
        while (!st.isEmpty()) {
            result.append(st.pop());
        }
        
        return result.reverse().toString();
    }
}
