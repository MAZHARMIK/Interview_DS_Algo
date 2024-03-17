/*    Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hnyEFhFmlo4
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/
*/

/*************************************************************** C++ ***************************************************************
//Approach-1 (Straight forward count)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        long long substrings = 0;
        
        for(char &ch : s) {
            if(ch == c) {
                substrings += (1 + count);
                count++;
            }
        }
        
        
        return substrings;
    }
};


//Approach-2 (Using simple math)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        
        for(char &ch : s) {
            if(ch == c) {
                count++;
            }
        }
        
        
        return count *(count-1)/2 + count;
    }
};


/*************************************************************** JAVA ***************************************************************
//Approach-1 (Straight forward count)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public long countSubstrings(String s, char c) {
        long count = 0;
        long substrings = 0;
        
        for (char ch : s.toCharArray()) {
            if (ch == c) {
                substrings += (1 + count);
                count++;
            }
        }
        
        return substrings;
    }
}

//Approach-2 (Using simple math)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public long countSubstrings(String s, char c) {
        long count = 0;
        
        for (char ch : s.toCharArray()) {
            if (ch == c) {
                count++;
            }
        }
        
        return count * (count - 1) / 2 + count;
    }
}
