/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4I1c9esy54s
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/find-the-count-of-good-integers
*/


/****************************************************** C++ **************************************************************/
//Approach (Using Maths + Strings)
//T.C : O(10^d * nlogn), where d = number of digits
//S.C : O(10^d * n)
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;

        int d = (n+1)/2;
        int start = pow(10, d-1);
        int end   = pow(10, d) - 1;

        for(int num = start; num <= end; num++) {
            string leftHalf = to_string(num);
            string full = "";

            if(n%2 == 0) {
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            } else {
                string rightHalf = leftHalf.substr(0, d-1);
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }

            long long number = stoll(full);
            if(number % k != 0)
                continue;
            
            sort(full.begin(), full.end());
            st.insert(full);
        }

        vector<long long> factorial(11, 1);
        for(int i = 1; i < 11; i++) {
            factorial[i] = factorial[i-1] * i;
        }
        long long result = 0;
        for(const string &s : st) {
            vector<int> count(10, 0);
            for(const char &ch : s) {
                count[ch - '0']++; //mp[ch]++
            }

            int totalDigits = s.length();
            int zeroDigits = count[0];
            int nonZeroDigits = totalDigits - zeroDigits;

            long long perm = (nonZeroDigits * factorial[totalDigits-1]);

            for(int i = 0; i < 10; i++) {
                perm /= factorial[count[i]];
            }

            result += perm;
        }

        return result;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach (Using Maths + Strings)
//T.C : O(10^d * nlogn), where d = number of digits
//S.C : O(10^d * n)
import java.util.*;

class Solution {
    public long countGoodIntegers(int n, int k) {
        Set<String> st = new HashSet<>();

        int d = (n + 1) / 2;
        int start = (int) Math.pow(10, d - 1);
        int end = (int) Math.pow(10, d) - 1;

        for (int num = start; num <= end; num++) {
            String leftHalf = Integer.toString(num);
            String full;

            if (n % 2 == 0) {
                StringBuilder rightHalf = new StringBuilder(leftHalf).reverse();
                full = leftHalf + rightHalf.toString();
            } else {
                StringBuilder rightHalf = new StringBuilder(leftHalf.substring(0, d - 1)).reverse();
                full = leftHalf + rightHalf.toString();
            }

            long number = Long.parseLong(full);
            if (number % k != 0)
                continue;

            char[] chars = full.toCharArray();
            Arrays.sort(chars);
            st.add(new String(chars));
        }

        long[] factorial = new long[11];
        factorial[0] = 1;
        for (int i = 1; i < 11; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long result = 0;
        for (String s : st) {
            int[] count = new int[10];
            for (char ch : s.toCharArray()) {
                count[ch - '0']++;
            }

            int totalDigits = s.length();
            int zeroDigits = count[0];
            int nonZeroDigits = totalDigits - zeroDigits;

            long perm = nonZeroDigits * factorial[totalDigits - 1];
            for (int i = 0; i < 10; i++) {
                perm /= factorial[count[i]];
            }

            result += perm;
        }

        return result;
    }
}
