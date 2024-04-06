/*          Scroll down to see JAVA code also         */
/*
        MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fGKk7DtQAmM
        Company Tags                : will update soon
        Leetcode Link               : https://leetcode.com/problems/shortest-common-supersequence/
*/

/************************************************************** C++ **************************************************************/
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j < n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = i+j;
                else if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
            }
        }
                
        string scs = "";
        int i = m,  j = n;
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                scs.push_back(s1[i-1]);
                i--;
                j--;
            } else {
                if(t[i-1][j] < t[i][j-1]) {
                    scs.push_back(s1[i-1]);
                    i--;
                } else {
                    scs.push_back(s2[j-1]);
                    j--;
                }
            }
        }

        //add remaining characters from both s1 and s2
        while(i > 0) {
            scs.push_back(s1[i-1]);
            i--;
        }
        while(j > 0) {
            scs.push_back(s2[j-1]);
            j--;
        }
        reverse(scs.begin(), scs.end());
        
        return scs;
    }
};



/************************************************************** JAVA ***************************************************************/
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public String shortestCommonSupersequence(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        int[][] t = new int[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = i + j;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = 1 + Math.min(t[i - 1][j], t[i][j - 1]);
            }
        }

        StringBuilder scsBuilder = new StringBuilder();
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                scsBuilder.append(s1.charAt(i - 1));
                i--;
                j--;
            } else {
                if (t[i - 1][j] < t[i][j - 1]) {
                    scsBuilder.append(s1.charAt(i - 1));
                    i--;
                } else {
                    scsBuilder.append(s2.charAt(j - 1));
                    j--;
                }
            }
        }

        // add remaining characters from both s1 and s2
        while (i > 0) {
            scsBuilder.append(s1.charAt(i - 1));
            i--;
        }
        while (j > 0) {
            scsBuilder.append(s2.charAt(j - 1));
            j--;
        }
        return scsBuilder.reverse().toString();
    }
}
