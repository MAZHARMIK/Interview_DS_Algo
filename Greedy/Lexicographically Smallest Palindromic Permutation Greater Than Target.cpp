/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iRjcsb6Ccms
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedy + backtracking)
//T.C : O(26*n) ~ O(n)
//S.C : O(n)
class Solution {
public:

    string result = "";
    char midChar = '$';
    int half = 0;

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if (i == half) {

            string candidate = curr; //left Half
            string rightHalf = candidate;
            reverse(begin(rightHalf), end(rightHalf)); //right half
            
            if(midChar != '$')
                candidate += midChar; //mid character

            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        
        for (char ch : s) 
            count[ch - 'a']++;

        int oddCount = 0;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) { 
                oddCount++; 
                midChar = c + 'a'; 
            }
        }
        if (oddCount > 1) 
            return "";

        // Left-half counts + middle char (only when n is odd).
        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n / 2;

        string curr;
        solve(curr, halfCount, target, 0, false);
        return result;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach (Greedy + backtracking)
//T.C : O(26*n) ~ O(n)
//S.C : O(n)
class Solution {

    String result = "";
    char midChar = '$';
    int half = 0;

    boolean solve(StringBuilder curr, int[] count, String target, int i, boolean greater) {
        if (i == half) {

            String leftHalf = curr.toString();                       // left half
            String rightHalf = new StringBuilder(leftHalf)
                                   .reverse().toString();            // right half

            String candidate = leftHalf;
            if (midChar != '$')
                candidate += midChar;                                // mid character
            candidate += rightHalf;

            if (candidate.compareTo(target) > 0) {                   // strictly greater
                result = candidate;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target.charAt(i))
                continue;

            curr.append(ch);
            count[ch - 'a']--;

            boolean isGreater = greater || ch > target.charAt(i);

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            curr.deleteCharAt(curr.length() - 1);
            count[ch - 'a']++;
        }

        return false;
    }

    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] count = new int[26];

        for (char ch : s.toCharArray())
            count[ch - 'a']++;

        int oddCount = 0;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) {
                oddCount++;
                midChar = (char) (c + 'a');
            }
        }
        if (oddCount > 1)
            return "";

        // Left-half counts + middle char (only when n is odd).
        int[] halfCount = new int[26];
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n / 2;

        StringBuilder curr = new StringBuilder();
        solve(curr, halfCount, target, 0, false);
        return result;
    }
}
