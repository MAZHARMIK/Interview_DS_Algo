/*          Scroll down to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=IRO_4X0csoc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-odd-binary-number
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (greedily assigning 1s)
//T.C : O(n)
//S.C : O(n) for result
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        
        string result = string(n, '0');
        
        int i = 0;
        
        for(char &ch : s) {
            if(ch == '1') { 

                if(result[n-1] == '1') {
                    result[i] = '1';
                    i++;
                } else {
                    result[n-1] = '1';
                }
            }
        }
        
        return result;
    }
};


//Approach-2 (Count 1s and assign)
//T.C : O(n)
//S.C : O(n) for result
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        
        string result = string(n, '0');
        
        int count_1 = count(s.begin(), s.end(), '1');
        
        int j = 0;
        
        while(count_1 > 1) {
            result[j] = '1';
            j++;
            
            count_1--;
        }
        
        result[n-1] = '1';
        return result;
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (greedily assigning 1s)
//T.C : O(n)
//S.C : O(n) for result
public class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();
        
        // Initialize result string with '0' of length n
        StringBuilder result = new StringBuilder();
        for (int k = 0; k < n; k++) {
            result.append('0');
        }
        
        int i = 0;
        
        for (char ch : s.toCharArray()) {
            if (ch == '1') {
                if (result.charAt(n - 1) == '1') {
                    result.setCharAt(i, '1');
                    i++;
                } else {
                    result.setCharAt(n - 1, '1');
                }
            }
        }
        
        return result.toString();
    }
}


//Approach-2 (Count 1s and assign)
//T.C : O(n)
//S.C : O(n) for result
public class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();

        // Initialize result string with '0' of length n
        StringBuilder result = new StringBuilder();
        for (int k = 0; k < n; k++) {
            result.append('0');
        }

        int countOnes = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '1') {
                countOnes++;
            }
        }


        int j = 0;

        while (countOnes > 1) {
            result.setCharAt(j, '1');
            j++;

            countOnes--;
        }

        result.setCharAt(n - 1, '1');
        return result.toString();
    }
}
