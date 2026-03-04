/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
*/


/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int count = 0;

        int i = 0;
        while(i < n) {
            if(s[i] == '1') {
                count++;
                while(i < n && s[i] == '1')
                    i++;
            } else {
                i++;
            }

            if(count > 1)
                return false;
        }
        
        return true;
    }
};



//Approach-2 (simply look for "01")
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkOnesSegment(string s) { 
      return s.find("01") == string::npos; 
    }
};




/*************************************************************************** JAVA ***************************************************************************/
//Approach-1 (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean checkOnesSegment(String s) {
        int n = s.length();
        int count = 0;

        int i = 0;
        while(i < n) {
            if(s.charAt(i) == '1') {
                count++;
                while(i < n && s.charAt(i) == '1')
                    i++;
            } else {
                i++;
            }

            if(count > 1)
                return false;
        }
        
        return true;
    }
}

//Approach-2 (simply look for "01")
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
}
