/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pMU1pwHBu1U
    Company Tags                : Facebook, Google (This qn was asked with variation : Leetcode-1641)
    Leetcode Link               : https://leetcode.com/problems/count-sorted-vowel-strings/
    
    Similar Qn                  : https://leetcode.com/problems/count-sorted-vowel-strings/
*/

/************************************************ C++ ************************************************/
//Approach-1 (Top Down - Recursion + Memo) 
//Time : O(n)
class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> t;
    long long solve(int ch, int n) {
        if(n == 0) {
            return 1;
        }

        if(t[ch][n] != -1) {
            return t[ch][n];
        }

        /*
            Accoring to question : 
            a -> e
            e -> a, i
            i -> a, e, o, u
            o -> i, u
            u -> a
        */

        if(ch == a) {
            return t[ch][n] = solve(e, n-1) % M;
        } else if(ch == e) {
            return t[ch][n] = (solve(a, n-1) + solve(i, n-1)) % M;
        } else if(ch == i) {
            return t[ch][n] = (solve(a, n-1) + solve(e, n-1) + solve(o, n-1) + solve(u, n-1)) % M;
        } else if(ch == o) {
            return t[ch][n] = (solve(i, n-1) + solve(u, n-1)) % M;
        } else { //ch == u
            return t[ch][n] = solve(a, n-1);
        }


        return t[ch][n] = 0;
    }

    int countVowelPermutation(int n) {
        t.resize(5, vector<long long>(n+1, -1));
        long result = 0;

        result = (result + solve(a, n-1)) % M;
        result = (result + solve(e, n-1)) % M;
        result = (result + solve(i, n-1)) % M;
        result = (result + solve(o, n-1)) % M;
        result = (result + solve(u, n-1)) % M;

        return result;

    }
};

//Approach-2 (Top Down DP : Just iterative version of Approach-1) 
//Time : O(n)
class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    int countVowelPermutation(int n) {

        long long t[5][n+1];
        //t[i][j] = number of strings ending at i vowel habing length j

        for(int vowel = 0; vowel <= 4; vowel++) {
            t[vowel][1] = 1;
        }

        for(int len = 2; len <= n; len++) {
            t[a][len] = (t[e][len-1] + t[i][len-1] + t[u][len-1]) % M;

            t[e][len] = (t[a][len-1] + t[i][len-1]) % M;

            t[i][len] = (t[e][len-1] + t[o][len-1]) % M;

            t[o][len] = (t[i][len-1]) % M;

            t[u][len] = (t[i][len-1] + t[o][len-1]) % M;
        }

        //t[a][n] + t[e][n] + t[i][n]....
        long long result = 0;
        for(int vowel = 0; vowel <= 4; vowel++) {
            result = (result + t[vowel][n]) % M;
        }
        return result;
   
    }
};


/************************************************ JAVA ************************************************/
//Approach-1 (Top Down - Recursion + Memo) 
//Time : O(n)
import java.util.Arrays;

public class Solution {
    private static final int M = 1000000007;
    private static final int a = 0, e = 1, i = 2, o = 3, u = 4;
    private long[][] t;

    private long solve(int ch, int n) {
        if (n == 0) {
            return 1;
        }

        if (t[ch][n] != -1) {
            return t[ch][n];
        }

        if (ch == a) {
            t[ch][n] = solve(e, n - 1) % M;
        } else if (ch == e) {
            t[ch][n] = (solve(a, n - 1) + solve(i, n - 1)) % M;
        } else if (ch == i) {
            t[ch][n] = (solve(a, n - 1) + solve(e, n - 1) + solve(o, n - 1) + solve(u, n - 1)) % M;
        } else if (ch == o) {
            t[ch][n] = (solve(i, n - 1) + solve(u, n - 1)) % M;
        } else { // ch == u
            t[ch][n] = solve(a, n - 1);
        }

        return t[ch][n];
    }

    public int countVowelPermutation(int n) {
        t = new long[5][n + 1];
        for (int i = 0; i < 5; i++) {
            Arrays.fill(t[i], -1);
        }

        long result = 0;
        result = (result + solve(a, n - 1)) % M;
        result = (result + solve(e, n - 1)) % M;
        result = (result + solve(i, n - 1)) % M;
        result = (result + solve(o, n - 1)) % M;
        result = (result + solve(u, n - 1)) % M;

        return (int) result;
    }
}


//Approach-2 (Top Down DP : Just iterative version of Approach-1) 
//Time : O(n)
public class Solution {
    private static final int M = 1000000007;
    private static final int a = 0, e = 1, i = 2, o = 3, u = 4;

    public int countVowelPermutation(int n) {
        long[][] t = new long[5][n + 1];

        for (int vowel = 0; vowel <= 4; vowel++) {
            t[vowel][1] = 1;
        }

        for (int len = 2; len <= n; len++) {
            t[a][len] = (t[e][len - 1] + t[i][len - 1] + t[u][len - 1]) % M;
            t[e][len] = (t[a][len - 1] + t[i][len - 1]) % M;
            t[i][len] = (t[e][len - 1] + t[o][len - 1]) % M;
            t[o][len] = t[i][len - 1] % M;
            t[u][len] = (t[i][len - 1] + t[o][len - 1]) % M;
        }

        long result = 0;
        for (int vowel = 0; vowel <= 4; vowel++) {
            result = (result + t[vowel][n]) % M;
        }

        return (int) result;
    }
}
