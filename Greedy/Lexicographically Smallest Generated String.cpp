/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=A2w3qAkYyQo
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-generated-string
*/


/************************************************************ C++ *****************************************************/
//Approach (Using Greedy)
//T.C : O(n*m)
//S.C : O(n+m-1)
class Solution {
public:
    bool isSame(string &word, string & str2, int i, int m) {
        for(int j = 0; j < m; j++) {
            if(word[i] != str2[j]) {
                return false;
            }

            i++;
        }

        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N, '$');

        vector<bool> canChange(N, false);

        //Process the 'T'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                int i_ = i;
                for(int j = 0; j < m; j++) {
                   //word[i] = str2[j]
                   //word[i+1] = str2[j+1] and so on....
                   if(word[i_] != '$' && word[i_] != str2[j]) {
                        return "";
                   }
                   word[i_] = str2[j];
                   i_++;
                }
            }
        }

        //FIll the remaining spaces with 'a'
        for(int i = 0; i < N; i++) {
            if(word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        //Process the 'F'
        //T.C : O(n * m)
        //S,C : O(N)
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {

                if(isSame(word, str2, i, m)) { //If same, then we need to make it unequal
                    
                    bool changed = false;
                    for(int k = i + m - 1; k >= i; k--) {
                        if(canChange[k] == true) {
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(changed == false) { //i was not able to change any character to break equality
                        return "";
                    }

                }

            }
        }

        return word;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Using Greedy)
//T.C : O(n*m)
//S.C : O(n+m-1)
class Solution {
    public String generateString(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        char[] word = new char[N];
        boolean[] canChange = new boolean[N];

        // Fill with placeholder
        for (int i = 0; i < N; i++) {
            word[i] = '$';
        }

        // Step 1: Process 'T'
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'T') {
                int idx = i;
                for (int j = 0; j < m; j++) {
                    if (word[idx] != '$' && word[idx] != str2.charAt(j)) {
                        return "";
                    }
                    word[idx] = str2.charAt(j);
                    idx++;
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for (int i = 0; i < N; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // Step 3: Process 'F'
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'F') {

                if (isSame(word, str2, i, m)) {
                    boolean changed = false;

                    for (int k = i + m - 1; k >= i; k--) {
                        if (canChange[k]) {
                            word[k] = 'b';  // minimal change
                            canChange[k] = false;
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return "";
                }
            }
        }

        return new String(word);
    }

    private boolean isSame(char[] word, String str2, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (word[i] != str2.charAt(j)) return false;
            i++;
        }
        return true;
    }
}
