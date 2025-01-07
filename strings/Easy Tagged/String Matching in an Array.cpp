/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=BsR6ZVwxrvE
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/string-matching-in-an-array

    My KMP Video - https://www.youtube.com/watch?v=qases-9gOpk
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n^2) , m = length of longest string in words, n = size of words
//S.C : O(1)
class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> result;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};



//Approach-2 (Using KMP)
//T.C : O(m*n^2), m = length of longest string in words, n = size of words
//S.C : O(m)
class Solution {
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

    bool searchKMP(string pat, string txt) {
        int N = txt.length();
        int M = pat.length();
        
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
                //result.push_back(i-j+1); //Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                //j = lps[j - 1];
                return true;
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;

                if(searchKMP(words[i], words[j])) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};



/*************************************************************************** JAVA ***************************************************************************/
// Approach-1 (Brute Force)
// T.C : O(m*n^2), m = length of longest string in words, n = size of words
// S.C : O(1)
class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> result = new ArrayList<>();
        int n = words.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (words[j].contains(words[i])) {
                    result.add(words[i]);
                    break;
                }
            }
        }

        return result;
    }
}

// Approach-2 (Using KMP)
// T.C : O(m*n^2), m = length of longest string in words, n = size of words
// S.C : O(m)
class Solution {
    // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
    private void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    private boolean searchKMP(String pat, String txt) {
        int N = txt.length();
        int M = pat.length();
        
        // Create an LPS array to store the longest proper prefix which is also a suffix
        // lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
        int[] lps = new int[M];
        computeLPS(pat, lps);
    
        int i = 0; // Index for text
        int j = 0; // Index for pattern
    
        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }
    
            if (j == M) {
                // result.add(i-j+1); // Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                // j = lps[j - 1];
                return true;
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return false;
    }

    public List<String> stringMatching(String[] words) {
        int n = words.length;
        List<String> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (searchKMP(words[i], words[j])) {
                    result.add(words[i]);
                    break;
                }
            }
        }

        return result;
    }
}


//Will add tonight when I get free time
