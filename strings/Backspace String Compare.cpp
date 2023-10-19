/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=u6K3j3n3vbA
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/backspace-string-compare/
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using extra space)
//T.C : O(n+m)
//S.C : O(m+n)
class Solution {
public:
    string buildString(string &s) {
        int n = s.length();
        string temp = "";
        
        int i = 0;
        while(i < n) {
            if(s[i] != '#') {
                temp.push_back(s[i]);
            } else if(!temp.empty()) {
                temp.pop_back();
            }
            i++;
        }
        
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
};


//Approach-2 (Using O(1) space)
//T.C : O(max(m, n))
//S.C : O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int i = m-1, j = n-1;
        int skip_s = 0;
        int skip_t = 0;
        
        while(i >= 0 || j >= 0) {
            
            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }
            
            while(j >= 0) {
                if(t[j] == '#') {
                    skip_t++;
                    j--;
                } else if(skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }
            
            char first  = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];
            
            if(first != second)
                return false;
            
            i--;
            j--;
        }
        
        return true;
        
    }
};


/******************************************************** JAVA ********************************************************/
//Approach-1 (Using extra space)
//T.C : O(n+m)
//S.C : O(m+n)
class Solution {
    public String buildString(String s) {
        int n = s.length();
        StringBuilder temp = new StringBuilder();
        
        int i = 0;
        while (i < n) {
            if (s.charAt(i) != '#') {
                temp.append(s.charAt(i));
            } else if (temp.length() > 0) {
                temp.deleteCharAt(temp.length() - 1);
            }
            i++;
        }
        
        return temp.toString();
    }
    
    public boolean backspaceCompare(String s, String t) {
        return buildString(s).equals(buildString(t));
    }
}



//Approach-2 (Using O(1) space)
//T.C : O(max(m, n))
//S.C : O(1)
class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s.charAt(i) == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (t.charAt(j) == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            char first = (i < 0) ? '$' : s.charAt(i);
            char second = (j < 0) ? '$' : t.charAt(j);
            
            if (first != second) {
                return false;
            }
            
            i--;
            j--;
        }
        
        return true;
    }
}
