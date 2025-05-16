/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WI9PhnDxAik
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/clear-digits/description/
*/


/********************************************* C++ *********************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int i = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {

                s.erase(i, 1);
                if (i > 0) {
                    s.erase(i - 1, 1);
                    i--;
                }
            } else {
                i++;
            }
        }
        return s;
    }
};


//Approach-2 (Using stack)
//T.C : O(n)
//S.C : O(n) for stack
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                st.push(ch);
            } else if(!st.empty()) {
                st.pop();
            }
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }
};


//Approach-3 (Using result string to avoid reverse call)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        string result = "";

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            } else if(!result.empty()) {
                result.pop_back();
            }
        }

        return result;
    }
};


//Approach-4 (Solving inplace)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                j = max(j - 1, 0); //max used to avoid negative
            } else {
                s[j] = s[i];
                j++;
            }
        }

        s.resize(j);
        return s;
    }
};



/********************************************* Java *********************************************/
// Approach-1 (Brute Force)  
// T.C : O(n^2)  
// S.C : O(1)  
class Solution {
    public String clearDigits(String s) {
        StringBuilder sb = new StringBuilder(s);
        int i = 0;

        while (i < sb.length()) {
            if (Character.isDigit(sb.charAt(i))) {
                sb.deleteCharAt(i);
                if (i > 0) {
                    sb.deleteCharAt(i - 1);
                    i--;
                }
            } else {
                i++;
            }
        }
        return sb.toString();
    }
}


// Approach-2 (Using stack)  
// T.C : O(n)  
// S.C : O(n) for stack  
class Solution {
    public String clearDigits(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch >= 'a' && ch <= 'z') {
                stack.push(ch);
            } else if (!stack.isEmpty()) {
                stack.pop();
            }
        }

        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.reverse().toString();
    }
}


// Approach-3 (Using result string to avoid reverse call)  
// T.C : O(n)  
// S.C : O(1)  
class Solution {
    public String clearDigits(String s) {
        StringBuilder result = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (ch >= 'a' && ch <= 'z') {
                result.append(ch);
            } else if (result.length() > 0) {
                result.deleteCharAt(result.length() - 1);
            }
        }

        return result.toString();
    }
}


// Approach-4 (Solving inplace)  
// T.C : O(n)  
// S.C : O(1)  
class Solution {
    public String clearDigits(String s) {
        char[] arr = s.toCharArray();
        int j = 0;

        for (int i = 0; i < arr.length; i++) {
            if (Character.isDigit(arr[i])) {
                j = Math.max(j - 1, 0);
            } else {
                arr[j] = arr[i];
                j++;
            }
        }

        return new String(arr, 0, j);
    }
}
