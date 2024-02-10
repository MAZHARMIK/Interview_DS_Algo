/*                                     Scroll down to see JAVA code also                                                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tGAMyZxlwuA
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/palindromic-substrings/description
*/


/******************************************************************** C++ ********************************************************************/
//Approach-1 (Simply check all substrings possilbe)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:

    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(s[i] == s[j]) {
            return check(s, i+1, j-1);
        }

        return false;

    }

    int countSubstrings(string s) {
        int n = s.length();

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { //check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};


//Approach-2 (Memoize the approach above)
//T.C : O(n^2) - Every subproblem is being computed only once and after that it's being reused
//S.C : O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(t[i][j] != -1) {
            return t[i][j]; //1 : True, 0 : False
        }

        if(s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }

        return t[i][j] = false;

    }

    int countSubstrings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { //check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};


//Approach-3(Bottom Up - My Favourite Blue Print of Pallindrome Qns)
//T.C : O(n^2)
//S.C ; O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices

        int count = 0;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    t[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true);
                }

                count += t[i][j];
            }
        }

        return count;
    }
};


//Approach-4 (Smart approach)
//T.C : O(n^2)
//S.C : o(1)
class Solution {
public:
    int count = 0;
    void check(string& s, int i, int j, int n) {
        
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--; //expanding from center
            j++; //expanding from center
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        
        /*
            
    Every single character in the string is a center for possible odd-length palindromes: check(s, i, i);
    Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1);.

        */
        for(int i = 0; i<n; i++) {
            check(s, i, i, n);
            check(s, i, i+1, n);
        }
        return count;
    }
};



/******************************************************************** JAVA ********************************************************************/
// Approach-1 (Simply check all substrings possible)
// T.C : O(n^3)
// S.C : O(1)
class Solution1 {
    public boolean check(String s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (s.charAt(i) == s.charAt(j)) {
            return check(s, i + 1, j - 1);
        }

        return false;
    }

    public int countSubstrings(String s) {
        int n = s.length();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // check all possible substrings
                if (check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
}

// Approach-2 (Memoize the approach above)
// T.C : O(n^2) - Every subproblem is being computed only once and after that, it's being reused
// S.C : O(n^2)
class Solution {
    int[][] t;

    public boolean check(String s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (t[i][j] != -1) {
            return t[i][j] == 1;
        }

        if (s.charAt(i) == s.charAt(j)) {
            boolean val = check(s, i+1, j-1);
            if(val == true)
                t[i][j] = 1;
            else
                t[i][j] = 0;
            return val;
        }

        t[i][j] = 0;
        return false;
    }

    public int countSubstrings(String s) {
        int n = s.length();
        t = new int[n][n];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // check all possible substrings
                if (check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
}


// Approach-3 (Bottom Up - My Favourite Blueprint of Palindrome Questions)
// T.C : O(n^2)
// S.C : O(n^2)
class Solution3 {
    public int countSubstrings(String s) {
        int n = s.length();
        boolean[][] t = new boolean[n][n];

        int count = 0;

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    t[i][i] = true; // Single characters are palindrome
                } else if (i + 1 == j) {
                    t[i][j] = (s.charAt(i) == s.charAt(j)); // Strings of 2 Length
                } else {
                    t[i][j] = (s.charAt(i) == s.charAt(j) && t[i + 1][j - 1]);
                }

                if (t[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
}


// Approach-4 (Smart approach)
// T.C : O(n^2)
// S.C : O(1)
class Solution4 {
    private int count = 0;

    private void check(String s, int i, int j, int n) {
        while (i >= 0 && j < n && s.charAt(i) == s.charAt(j)) {
            count++;
            i--; // expanding from center
            j++; // expanding from center
        }
    }

    public int countSubstrings(String s) {
        int n = s.length();
        count = 0;

        /*
         * Every single character in the string is a center for possible odd-length
         * palindromes: check(s, i, i); Every pair of consecutive characters in the
         * string is a center for possible even-length palindromes: check(s, i, i+1);
         */
        for (int i = 0; i < n; i++) {
            check(s, i, i, n);
            check(s, i, i + 1, n);
        }
        return count;
    }
}
