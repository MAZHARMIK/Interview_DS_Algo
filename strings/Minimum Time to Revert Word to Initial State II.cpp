/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4lrczVkMYko
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i
*/


/***************************************************************** C++ *****************************************************************/
//Approach-1 (Brute Force - Baby Steps)
//T.C : O(n^2)
//S.C : O(1)
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Minimum%20Time%20to%20Revert%20Word%20to%20Initial%20State%20I.cpp


//Approach-2 (Optimal using KMP LPS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:

    //copy paste of KMP LPS which I taught
    void LPS(string &word, vector<int>& lps, int n) {
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while(i < n) {
            if(word[i] == word[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();

        vector<int> lps(n);
        LPS(word, lps, n);

        int maxLps = lps[n-1];

        while(maxLps > 0 && (n-maxLps)%k != 0) {
            maxLps = lps[maxLps-1];
        }

        if((n-maxLps)%k == 0) {
            return (n-maxLps)/k;
        }

        return ceil(n/(double)k); //or, (n + k - 1)/k
    }
};



/***************************************************************** JAVA *****************************************************************/
//Approach-1 (Brute Force - Baby Steps)
//T.C : O(n^2)
//S.C : O(1)
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Minimum%20Time%20to%20Revert%20Word%20to%20Initial%20State%20I.cpp


//Approach-2 (Optimal using KMP LPS)
//T.C : O(n)
//S.C : O(n)
public class Solution {

    // Copy paste of KMP LPS which I taught
    void LPS(String word, int[] lps, int n) {
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < n) {
            if (word.charAt(i) == word.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int minimumTimeToInitialState(String word, int k) {
        int n = word.length();

        int[] lps = new int[n];
        LPS(word, lps, n);

        int maxLps = lps[n - 1];

        while (maxLps > 0 && (n - maxLps) % k != 0) {
            maxLps = lps[maxLps - 1];
        }

        if ((n - maxLps) % k == 0) {
            return (n - maxLps) / k;
        }

        return (int) Math.ceil(n / (double) k); // or, (n + k - 1)/k
    }
}
