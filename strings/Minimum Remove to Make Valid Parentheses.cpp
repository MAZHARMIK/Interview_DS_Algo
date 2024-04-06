/*    Scroll down to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=NNxaYz0nrk0
    Company Tags  : Facebook, Amazon, Bloomberg, Google, tiktok, Adobe
    Frequency     : Facebook(111), Amazon(7), Bloomberg(4), Google(3), tiktok(2), Adobe(2) - I got this information from my friends. Please verify
    Leetcode Link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

/***************************************************************************** C++ **********************************************************************/
//Approach-1 (Using Stack and set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        unordered_set<int> toRemove;
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') //store index of '('
                st.push(i);
            else  if(s[i] == ')') {
                if(st.empty()) { //invalid ')'
                    toRemove.insert(i);
                } else {
                    st.pop(); //balancing with open '('
                }
            }
        }
        
        //suppose the input is  "(("
        //Then, we won't be adding them in the toRemove set to remove later
        //So, adding here
        while(!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }
        
        string result = "";
        
        for(int i = 0; i<n; i++) {
            if(toRemove.find(i) == toRemove.end())
                result.push_back(s[i]);
        }
        
        return result;
    }
};


//Approach-2 (Iterate from front and eliminate and then iterate from back and eliminate)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        int n = s.length();
        
        //Iterate fron front and eliminate
        int lastOpen = 0;
        for(int i = 0; i<n; i++) {
            char c = s[i];
            if((c >= 'a' && c <= 'z'))
                result.push_back(c);
            else if(c == '(') {
                result.push_back(c);
                lastOpen++;
            } else if(lastOpen > 0) {
                lastOpen--;
                result.push_back(c);
            }
        }
        
        if(result == "")
            return "";
        
        
        s = result;
        result = "";
        int lastClose = 0;
        n = s.length();
        //Iterate fron back and eliminate
        for(int i = n-1; i>=0; i--) {
            char c = s[i];
            if((c >= 'a' && c <= 'z'))
                result.push_back(c);
            else if(c == ')') {
                result.push_back(c);
                lastClose++;
            } else if(lastClose > 0) {
                lastClose--;
                result.push_back(c);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};



//Approach-3 (Simplified : Playing smart and keeping it simple)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        string temp = "";
        
        for(char c:s) {
            if(c == '(') {
                open++;
            } else if(c == ')') {
                if(open == 0)
                    continue;
                open--;
            }
            
            temp.push_back(c);
        }
        
        int n = temp.length();
        string result = "";
        for(int i = n-1; i>=0; i--) {
            if(temp[i] == '(' && open-- > 0)
                continue;
            result.push_back(temp[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};



/***************************************************************************** C++ **********************************************************************/
//Approach-1 (Using Stack and set)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();
        
        HashSet<Integer> toRemove = new HashSet<>();
        Stack<Integer> st = new Stack<>();
        
        for(int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if(ch == '(') 
                st.push(i);
            else if(ch == ')') {
                if(st.isEmpty()) 
                    toRemove.add(i);
                else 
                    st.pop();
            }
        }
        
        while(!st.isEmpty()) 
            toRemove.add(st.pop());
        
        StringBuilder result = new StringBuilder();
        
        for(int i = 0; i < n; i++) {
            if(!toRemove.contains(i))
                result.append(s.charAt(i));
        }
        
        return result.toString();
    }
}


//Approach-2 (Iterate from front and eliminate and then iterate from back and eliminate)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder result = new StringBuilder();
        int n = s.length();
        
        int lastOpen = 0;
        for(int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if(Character.isLetter(c)) 
                result.append(c);
            else if(c == '(') {
                result.append(c);
                lastOpen++;
            } else if(lastOpen > 0) {
                lastOpen--;
                result.append(c);
            }
        }
        
        if(result.length() == 0)
            return "";
        
        s = result.toString();
        result = new StringBuilder();
        int lastClose = 0;
        n = s.length();
        for(int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if(Character.isLetter(c))
                result.insert(0, c);
            else if(c == ')') {
                result.insert(0, c);
                lastClose++;
            } else if(lastClose > 0) {
                lastClose--;
                result.insert(0, c);
            }
        }
        return result.toString();
    }
}


//Approach-3 (Simplified : Playing smart and keeping it simple)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public String minRemoveToMakeValid(String s) {
        int open = 0;
        StringBuilder temp = new StringBuilder();
        
        for(char c: s.toCharArray()) {
            if(c == '(') 
                open++;
            else if(c == ')') {
                if(open == 0)
                    continue;
                open--;
            }
            
            temp.append(c);
        }
        
        StringBuilder result = new StringBuilder();
        for(int i = temp.length() - 1; i >= 0; i--) {
            if(temp.charAt(i) == '(' && open-- > 0)
                continue;
            result.insert(0, temp.charAt(i));
        }
        
        return result.toString();
    }
}
