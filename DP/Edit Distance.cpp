/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oqfqPEqrKo8
    Company Tags                : Amazon, Goldman Sachs, Microsoft, Google
    Leetcode Qn Link            : https://leetcode.com/problems/edit-distance/
*/

/********************************************** C++ *********************************************/
//Approach-1 (Recur + Memo, starting from m, n)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[501][501];
    int solve(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return m+n;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = solve(s1, s2, m-1, n-1);
        else {
            int insertC  = 1 + solve(s1, s2, m, n-1);
            int deleteC  = 1 + solve(s1, s2, m-1, n);
            int replaceC = 1 + solve(s1, s2, m-1, n-1);
            
            return t[m][n] = min({insertC, deleteC, replaceC});
        }
        
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m, n);
    }
};

//Approach-2 (Recur + Memo, starting from i = 0, j = 0)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[501][501];
    int m, n;
    int solve(string& s1, string& s2, int i, int j) {
        if(i == m)
            return n-j;
        else if(j == n)
            return m-i;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(s1[i] == s2[j])
            return t[i][j] = solve(s1, s2, i+1, j+1);
        else {
            int insertC  = 1 + solve(s1, s2, i, j+1);
            int deleteC  = 1 + solve(s1, s2, i+1, j);
            int replaceC = 1 + solve(s1, s2, i+1, j+1);
            
            return t[i][j] = min({insertC, deleteC, replaceC});
        }
        
    }
    
    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, 0, 0);
    }
};


//Approach-3 (Using Bottom Up derived from Approach-1)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int editDistance(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = i+j;
                else if(s1[i-1] == s2[j-1])
                    t[i][j] = t[i-1][j-1];
                else
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j], t[i-1][j-1]});
            }
        }
        return t[m][n];
    }
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        return editDistance(s1, s2, m, n);
    }
};



/********************************************** JAVA *********************************************/
//Approach-1 (Recur + Memo, starting from m, n)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int[][] t = new int[501][501];

    public int solve(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0)
            return m + n;

        if (t[m][n] != -1)
            return t[m][n];

        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return t[m][n] = solve(s1, s2, m - 1, n - 1);
        else {
            int insertC = 1 + solve(s1, s2, m, n - 1);
            int deleteC = 1 + solve(s1, s2, m - 1, n);
            int replaceC = 1 + solve(s1, s2, m - 1, n - 1);

            return t[m][n] = Math.min(Math.min(insertC, deleteC), replaceC);
        }
    }

    public int minDistance(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        for (int[] row : t)
            Arrays.fill(row, -1);

        return solve(s1, s2, m, n);
    }
}

//Approach-2 (Recur + Memo, starting from i = 0, j = 0)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int[][] t = new int[501][501];
    int m, n;

    public int solve(String s1, String s2, int i, int j) {
        if (i == m)
            return n - j;
        else if (j == n)
            return m - i;

        if (t[i][j] != -1)
            return t[i][j];

        if (s1.charAt(i) == s2.charAt(j))
            return t[i][j] = solve(s1, s2, i + 1, j + 1);
        else {
            int insertC = 1 + solve(s1, s2, i, j + 1);
            int deleteC = 1 + solve(s1, s2, i + 1, j);
            int replaceC = 1 + solve(s1, s2, i + 1, j + 1);

            return t[i][j] = Math.min(Math.min(insertC, deleteC), replaceC);
        }

    }

    public int minDistance(String s1, String s2) {
        m = s1.length();
        n = s2.length();
        for (int[] row : t)
            Arrays.fill(row, -1);

        return solve(s1, s2, 0, 0);
    }
}


//Approach-3 (Using Bottom Up derived from Approach-1)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public int editDistance(String s1, String s2, int m, int n) {
        int[][] t = new int[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = i + j;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    t[i][j] = t[i - 1][j - 1];
                else
                    t[i][j] = 1 + Math.min(Math.min(t[i][j - 1], t[i - 1][j]), t[i - 1][j - 1]);
            }
        }
        return t[m][n];
    }

    public int minDistance(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        return editDistance(s1, s2, m, n);
    }
}
