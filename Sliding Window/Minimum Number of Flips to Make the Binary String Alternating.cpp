/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=T3lhIT7hbl4
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (Sliding Window + modifying input s = s+s)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2 and s+=s
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = INT_MAX;

        while(j < 2*n) {

            // expand window
            if(s[j] != s1[j]) result1++;
            if(s[j] != s2[j]) result2++;

            // shrink if window exceeds n
            if(j - i + 1 > n) {
                if(s[i] != s1[i]) result1--;
                if(s[i] != s2[i]) result2--;
                i++;
            }

            // window size exactly n
            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};



//Approach-2 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = INT_MAX;

        while(j < 2*n) {
            
            // expand window
            if(s[j%n] != s1[j]) 
                result1++;
            if(s[j%n] != s2[j]) 
                result2++;

            // shrink if window exceeds n
            if(j - i + 1 > n) {
                if(s[i%n] != s1[i]) 
                    result1--;
                if(s[i%n] != s2[i]) 
                    result2--;
                i++;
            }

            // window size exactly n
            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};


//Approach-3 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        //khandani sliding window
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n) {

            char expectedCharS1 = (j%2) ? '1' : '0';
            char expectedCharS2 = (j%2) ? '0' : '1';

            if(s[j%n] != expectedCharS1) {
                flip1++;
            }

            if(s[j%n] != expectedCharS2) {
                flip2++;
            }

            if(j-i+1 > n) { //shrink the window from left
                expectedCharS1 = (i%2) ? '1' : '0';
                expectedCharS2 = (i%2) ? '0' : '1';

                if(s[i%n] != expectedCharS1) {
                    flip1--;
                }

                if(s[i%n] != expectedCharS2) {
                    flip2--;
                }

                i++;
            }

            if(j-i+1 == n) {
                result = min({result, flip1, flip2});
            }

            j++;

        }
        return result;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach-1 (Sliding Window + modifying input s = s+s)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2 and s+=s
class Solution {
    public int minFlips(String s) {

        int n = s.length();
        s = s + s;

        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for(int i = 0; i < 2*n; i++) {
            s1.append(i % 2 == 1 ? '0' : '1');
            s2.append(i % 2 == 1 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = Integer.MAX_VALUE;

        while(j < 2*n) {

            // expand window
            if(s.charAt(j) != s1.charAt(j)) result1++;
            if(s.charAt(j) != s2.charAt(j)) result2++;

            // shrink window
            if(j - i + 1 > n) {
                if(s.charAt(i) != s1.charAt(i)) result1--;
                if(s.charAt(i) != s2.charAt(i)) result2--;
                i++;
            }

            // window size n
            if(j - i + 1 == n)
                result = Math.min(result, Math.min(result1, result2));

            j++;
        }

        return result;
    }
}



//Approach-2 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2
class Solution {
    public int minFlips(String s) {

        int n = s.length();

        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for(int i = 0; i < 2*n; i++) {
            s1.append(i % 2 == 1 ? '0' : '1');
            s2.append(i % 2 == 1 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = Integer.MAX_VALUE;

        while(j < 2*n) {

            // expand window
            if(s.charAt(j % n) != s1.charAt(j)) result1++;
            if(s.charAt(j % n) != s2.charAt(j)) result2++;

            // shrink window
            if(j - i + 1 > n) {
                if(s.charAt(i % n) != s1.charAt(i)) result1--;
                if(s.charAt(i % n) != s2.charAt(i)) result2--;
                i++;
            }

            if(j - i + 1 == n)
                result = Math.min(result, Math.min(result1, result2));

            j++;
        }

        return result;
    }
}



//Approach-3 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
    public int minFlips(String s) {

        int n = s.length();

        int result = Integer.MAX_VALUE;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0, j = 0;

        while(j < 2*n) {

            char expectedCharS1 = (j % 2 == 1) ? '1' : '0';
            char expectedCharS2 = (j % 2 == 1) ? '0' : '1';

            if(s.charAt(j % n) != expectedCharS1) flip1++;
            if(s.charAt(j % n) != expectedCharS2) flip2++;

            if(j - i + 1 > n) {

                expectedCharS1 = (i % 2 == 1) ? '1' : '0';
                expectedCharS2 = (i % 2 == 1) ? '0' : '1';

                if(s.charAt(i % n) != expectedCharS1) flip1--;
                if(s.charAt(i % n) != expectedCharS2) flip2--;

                i++;
            }

            if(j - i + 1 == n)
                result = Math.min(result, Math.min(flip1, flip2));

            j++;
        }

        return result;
    }
}
