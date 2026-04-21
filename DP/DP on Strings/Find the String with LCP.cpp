/*     Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=LBeyZTNybMQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-string-with-lcp/
*/


/****************************************************************** C++ **********************************************************/
//Approach-1 (Using Greedy Allocation + Finding LCP and comparing)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    vector<vector<int>> LongestCommonPrefixMatrix (string s) {
        int n = s.length();
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; j ++) {
            result[n-1][j] = result[j][n-1] = (s[j] == s[n-1])? 1 : 0; 
        }
        for (int i = n-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                result[i][j] = (s[i] == s[j])? 1 + result[i+1][j+1] : 0;
            }
        }
        
        return result;
    }
    
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        string result (n, 'a');
        
        for (int i = 1; i < n; i ++) {
            vector<bool> not_equal(26, false);
            bool matched = false;
            
            for (int j = 0; j < i; j ++) {
                if (lcp[j][i] == 0) {
                    not_equal[result[j] - 'a'] = true;
                    continue;
                }
                
                matched = true;
                result[i] = result[j];
                break;
            }
        
            if (matched) continue;
            for (int j = 0; j < 26; j ++) {
                if (not_equal[j]) continue;
                
                result[i] = (char)('a' + j);
                break;
            }
        }
        
        if (LongestCommonPrefixMatrix(result) == lcp) return result;
        return "";
    }
};



//Approach-2 (Using Greedy Allocation + Without finding LCP)
//T.C : O(n^2)
//S.C : O(n) for word
class Solution {
public:
    bool checkLCP(string &word, vector<vector<int>>& lcp) {
        int n = word.length();

        for(int i = 0; i < n; i++) {
            //lcp[i][n-1] = (word[i] == word[n-1]) ? 1 : 0;
            if(word[i] != word[n-1]) {
                if(lcp[i][n-1] != 0) return false;
            } else {
                if(lcp[i][n-1] != 1) return false;
            }
        }

        for(int j = 0; j < n; j++) {
            //lcp[n-1][j] = (word[n-1] == word[j]) ? 1 : 0;
            if(word[n-1] != word[j]) {
                if(lcp[n-1][j] != 0) return false;
            } else {
                if(lcp[n-1][j] != 1) return false;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(word[i] == word[j]) {
                    if(lcp[i][j] != 1 + lcp[i+1][j+1]) return false;
                } else {
                    if(lcp[i][j] != 0) return false;
                }
            }
        }

        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i = 0; i < n; i++) {

            //word[i] = ?
            for(int j = 0; j < i; j++) {
                if(lcp[j][i] != 0) {
                    word[i] = word[j];
                    break;
                }
            }


            if(word[i] == '$') {
                vector<bool> forbidden(26, false);

                for(int j = 0; j < i; j++) {
                    if(lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                //a, b, c ..., z
                for(int idx = 0; idx < 26; idx++) {
                    if(forbidden[idx] == false) {
                        word[i] = idx + 'a';
                        break;
                    }
                }

                if(word[i] == '$')
                    return ""; //we could never fill word[i]
            }
        }

        return checkLCP(word, lcp) == true ? word : "";
    }
};



/****************************************************************** JAVA **********************************************************/
//Approach (Using Greedy Allocation + Comparing LCP)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {

    private int[][] checkLCP(String word) {
        int n = word.length();
        int[][] lcp = new int[n][n];

        // last column
        for (int i = 0; i < n; i++) {
            lcp[i][n - 1] = (word.charAt(i) == word.charAt(n - 1)) ? 1 : 0;
        }

        // last row
        for (int j = 0; j < n; j++) {
            lcp[n - 1][j] = (word.charAt(n - 1) == word.charAt(j)) ? 1 : 0;
        }

        // fill rest bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (word.charAt(i) == word.charAt(j)) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                } else {
                    lcp[i][j] = 0;
                }
            }
        }

        return lcp;
    }

    public String findTheString(int[][] lcp) {
        int n = lcp.length;
        char[] word = new char[n];

        // initialize with placeholder
        for (int i = 0; i < n; i++) {
            word[i] = '$';
        }

        for (int i = 0; i < n; i++) {

            // Step 1: try to match with previous
            for (int j = 0; j < i; j++) {
                if (lcp[j][i] != 0) {
                    word[i] = word[j];
                    break;
                }
            }

            // Step 2: assign smallest valid character
            if (word[i] == '$') {
                boolean[] forbidden = new boolean[26];

                for (int j = 0; j < i; j++) {
                    if (lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                for (int c = 0; c < 26; c++) {
                    if (!forbidden[c]) {
                        word[i] = (char) ('a' + c);
                        break;
                    }
                }

                // no valid character possible
                if (word[i] == '$') {
                    return "";
                }
            }
        }

        String result = new String(word);

        // Final validation
        int[][] computed = checkLCP(result);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computed[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return result;
    }
}



//Approach-2 (Using Greedy Allocation + Without finding LCP)
//T.C : O(n^2)
//S.C : O(n) for word
class Solution {

    public boolean checkLCP(String word, int[][] lcp) {
        int n = word.length();

        // Last column
        for (int i = 0; i < n; i++) {
            if (word.charAt(i) != word.charAt(n - 1)) {
                if (lcp[i][n - 1] != 0) return false;
            } else {
                if (lcp[i][n - 1] != 1) return false;
            }
        }

        // Last row
        for (int j = 0; j < n; j++) {
            if (word.charAt(n - 1) != word.charAt(j)) {
                if (lcp[n - 1][j] != 0) return false;
            } else {
                if (lcp[n - 1][j] != 1) return false;
            }
        }

        // Remaining cells
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (word.charAt(i) == word.charAt(j)) {
                    if (lcp[i][j] != 1 + lcp[i + 1][j + 1]) return false;
                } else {
                    if (lcp[i][j] != 0) return false;
                }
            }
        }

        return true;
    }

    public String findTheString(int[][] lcp) {
        int n = lcp.length;

        char[] word = new char[n];
        for (int i = 0; i < n; i++) {
            word[i] = '$';
        }

        for (int i = 0; i < n; i++) {

            // Try to match with previous
            for (int j = 0; j < i; j++) {
                if (lcp[j][i] != 0) {
                    word[i] = word[j];
                    break;
                }
            }

            // Assign smallest valid character
            if (word[i] == '$') {
                boolean[] forbidden = new boolean[26];

                for (int j = 0; j < i; j++) {
                    if (lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                for (int idx = 0; idx < 26; idx++) {
                    if (!forbidden[idx]) {
                        word[i] = (char) ('a' + idx);
                        break;
                    }
                }

                if (word[i] == '$') {
                    return "";
                }
            }
        }

        String result = new String(word);
        return checkLCP(result, lcp) ? result : "";
    }
}
