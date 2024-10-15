/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/separate-black-and-white-balls
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        long long swap  = 0;
        int black = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') { //move white to left
                swap += black;
            } else {
                black++;
            }
        }

        return swap;
    }
};


//Approach-2 (Reversed traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        long long swap  = 0;
        int white = 0;

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') { //move black to right
                swap += white;
            } else {
                white++;
            }
        }

        return swap;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long minimumSteps(String s) {
        int n = s.length();
        long swaps = 0;
        int black = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {  // Move white to the left
                swaps += black;
            } else {  // If it's black ('1'), increment black count
                black++;
            }
        }

        return swaps;
    }
}

//Approach-2 (Reversed traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long minimumSteps(String s) {
        int n = s.length();
        long swaps = 0;
        int white = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '1') {  // Move black to the right
                swaps += white;
            } else {  // If it's white ('0'), increment white count
                white++;
            }
        }

        return swaps;
    }
}
