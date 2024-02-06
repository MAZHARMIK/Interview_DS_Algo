/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qases-9gOpk
    Company Tags                : MICROSOFT
    GfG Link                    : https://www.geeksforgeeks.org/problems/search-pattern0205/1
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force) 
//Simply try with every possible index at i and iterate on pattern and keep trying.
//T.C : O(m*n)
//S.C : O(1)


//Approach-2 (KMP Algorithm)
//T.C : O(m+n)
//S.C : O(m) where m is the length of pattern
class Solution
{
    public:
        // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
        void computeLPS(string pattern, vector<int>& lps) {
            int M = pattern.length();
            int len = 0; // Length of the previous longest prefix & suffix
        
            lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
        
            int i = 1;
            while (i < M) {
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len - 1]; //You can also write, len = len-1;
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }
        
        vector <int> search(string pat, string txt) {
            int N = txt.length();
            int M = pat.length();
            vector<int> result;
            
            // Create an LPS array to store the longest proper prefix which is also a suffix
            //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
            vector<int> lps(M, 0);
            computeLPS(pat, lps);
        
            int i = 0; // Index for text
            int j = 0; // Index for pattern
        
            while (i < N) {
                if (pat[j] == txt[i]) {
                    i++;
                    j++;
                }
        
                if (j == M) {
                    result.push_back(i-j+1); //Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                    j = lps[j - 1];
                } else if (i < N && pat[j] != txt[i]) {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            
            return result;
        }
     
};


/**************************************************************** JAVA ****************************************************************/
//(KMP Algorithm)
//T.C : O(m+n)
//S.C : O(m) where m is the length of pattern
class Solution {

    ArrayList<Integer> search(String pat, String txt) {
        ArrayList<Integer> result = new ArrayList<>();
        int N = txt.length();
        int M = pat.length();

        int[] lps = computeLPS(pat);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < N) {
            if (j < M && pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == M) {
                result.add(i - j + 1); // Pattern found at index i - j + 1 (1-based indexing)
                j = lps[j - 1];
            } else if (i < N && (j == 0 || pat.charAt(j) != txt.charAt(i))) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    private int[] computeLPS(String pattern) {
        int M = pattern.length();
        int[] lps = new int[M];
        int len = 0; // Length of the previous longest prefix suffix

        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]

        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
}
