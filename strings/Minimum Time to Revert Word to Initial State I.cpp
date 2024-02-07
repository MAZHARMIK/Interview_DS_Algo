/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4lrczVkMYko
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i
*/

/***************************************************************** C++ *****************************************************************/
//Approach-1 (Brute Force - Baby Steps)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    
    bool check(string &word, int i) {
        int j = 0;
        
        while(i < word.length()) {
            if(word[i] == word[j]) {
                i++;
                j++;
            } else {
                break;
            }
        }
        
        return i == word.length();
    }
    
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        
        int count = 1;
        int i = k;
        
        while(i < n) {
            
            if(check(word, i)) {
                break;
            }
            
            count++;
            i += k;
            
        }
        
        return count;
        
    }
};


//Approach-2 (Brute Force - Smartly Clean Approach)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    
    bool check(string &word, int i, int n) {
        return word.substr(i, n-i) == word.substr(0, n-i);
    }
    
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        
        int count = 1;
        int i = k;
        
        while(i < n) {
            
            if(check(word, i, n)) {
                break;
            }
            
            count++;
            i += k;
            
        }
        
        return count;
        
    }
};



/***************************************************************** JAVA *****************************************************************/
//Approach-1 (Brute Force - Baby Steps)
//T.C : O(n^2)
//S.C : O(1)
public class Solution {
    private boolean check(String word, int i) {
        int j = 0;

        while (i < word.length()) {
            if (word.charAt(i) == word.charAt(j)) {
                i++;
                j++;
            } else {
                break;
            }
        }

        return i == word.length();
    }

    public int minimumTimeToInitialState(String word, int k) {
        int n = word.length();

        int count = 1;
        int i = k;

        while (i < n) {
            if (check(word, i)) {
                break;
            }

            count++;
            i += k;
        }

        return count;
    }
}



//Approach-2 (Brute Force - Smartly Clean Approach)
//T.C : O(n^2)
//S.C : O(1)
public class Solution {
    private boolean check(String word, int i, int n) {
        return word.substring(i, n).equals(word.substring(0, n - i));
    }

    public int minimumTimeToInitialState(String word, int k) {
        int n = word.length();

        int count = 1;
        int i = k;

        while (i < n) {
            if (check(word, i, n)) {
                break;
            }

            count++;
            i += k;
        }

        return count;
    }
}
