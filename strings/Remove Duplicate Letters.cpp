/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rU5p0MRm5zU
      Company Tags                : GOOGLE, Oracle Online Assessment
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

//Approach-3 (Using Recursion + Backtracking) - Not a good solution because contraints are high
/*
At ever character i have two choices - take or not take.
I can take it if that character is not taken before.
Once I reach out of bounds, i will see my temp string and keeping updating the result which is lexically smaller
*/
class Solution {
public:
    string result = "";
    int n;
    int unique_characters;
    
    void solve(int idx, string s, string temp, unordered_set<char>& st) {
        if(idx >= n) {
            if(result == "")
                result = s;
            else if(temp.size() == unique_characters)
                result = result > temp ? temp : result;
            
            return;
        }
        
        if(st.find(s[idx]) == st.end()) {
            temp.push_back(s[idx]); //taking idx'th char
            st.insert(s[idx]);
            solve(idx+1, s, temp, st);
            
            //Removing it for trying "Not Taking this Char"
            st.erase(s[idx]); //Not taking idx'th char
            temp.pop_back();
        }
        
        solve(idx+1, s, temp, st);
    }
    
    string removeDuplicateLetters(string s) {
        n = s.length();
        unordered_set<char> st;
        
        for(char &ch : s) {
            st.insert(ch);
        }
        unique_characters = st.size();
        
        st.clear();
        
        solve(0, s, "", st);
        
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


//Approach-3 (Using Recursion + Backtracking) - Not a good solution because contraints are high
/*
At ever character i have two choices - take or not take.
I can take it if that character is not taken before.
Once I reach out of bounds, i will see my temp string and keeping updating the result which is lexically smaller
*/
public class Solution {
    String result = "";
    int n;
    int uniqueCharacters;

    public String removeDuplicateLetters(String s) {
        n = s.length();
        HashSet<Character> st = new HashSet<>();

        for (char ch : s.toCharArray()) {
            st.add(ch);
        }
        uniqueCharacters = st.size();

        st.clear();

        solve(0, s, new StringBuilder(), st);

        return result;
    }

    private void solve(int idx, String s, StringBuilder temp, HashSet<Character> st) {
        if (idx >= n) {
            if (result.isEmpty()) {
                result = temp.toString();
            } else if (temp.length() == uniqueCharacters) {
                result = result.compareTo(temp.toString()) > 0 ? temp.toString() : result;
            }

            return;
        }

        if (!st.contains(s.charAt(idx))) {
            temp.append(s.charAt(idx)); // Taking idx'th char
            st.add(s.charAt(idx));
            solve(idx + 1, s, temp, st);

            // Removing it for trying "Not Taking this Char"
            st.remove(s.charAt(idx)); // Not taking idx'th char
            temp.deleteCharAt(temp.length() - 1);
        }

        solve(idx + 1, s, temp, st);
    }
}
