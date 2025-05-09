/*     Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=_9YlLoFT8JQ
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/count-number-of-balanced-permutations
*/


/****************************************************************** C++ **********************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * n!)
//S.C : O(n * n!), storing all permutations in set
class Solution {
public:
    int countBalancedPermutations(string num) {
        sort(num.begin(), num.end()); //Sorting helps next_permutation to find all permutation, so we need to start from smallest (hence sorted)
        unordered_set<string> seen;
        int count = 0;

        do {
            if (seen.count(num)) 
                continue;
            seen.insert(num);
            int evenSum = 0, oddSum = 0;
            for (int i = 0; i < num.size(); ++i) {
                int digit = num[i] - '0';
                if (i % 2 == 0) evenSum += digit;
                else oddSum += digit;
            }
            if (evenSum == oddSum) {
                count++;
            }
        } while (next_permutation(num.begin(), num.end()));

        return count;
    }
};


//Approach-2 (Recursion + Memoization)
//T.C : O(10 * n^2 * Sum)
//S.C : O(10 ^ n * Sum)
class Solution {
public:
    int n;
    int totalDigitSum;
    int M = 1e9 + 7;
    long long totalPermPossible = 0;

    //Binary exponentian
    int findPower(long long a, long long b) {
        if(b == 0) {
            return 1;
        }

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;
        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int solve(int digit, int evenIndexDigitsCount, int currSum, 
            vector<int>& freq, vector<long long>& fermatFact, 
            vector<vector<vector<int>>> &t) {
        if(digit == 10) {
            if(currSum == totalDigitSum/2 && evenIndexDigitsCount == (n+1)/2) {
                return totalPermPossible;
            }
            return 0;
        }

        if(t[digit][evenIndexDigitsCount][currSum] != -1) {
            return t[digit][evenIndexDigitsCount][currSum];
        }
        long long ways = 0;

        for(int count = 0; count <= min(freq[digit], (n+1)/2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount  = freq[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])% M;

            long long val = solve(digit+1, evenIndexDigitsCount + evenPosCount, currSum + digit*count, freq, fermatFact, t);

            ways = (ways + (val * div) % M) % M;
        }

        return t[digit][evenIndexDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n   = num.length();
        totalDigitSum = 0;

        vector<int> freq(10, 0);
        for(int i = 0; i < n; i++) {
            totalDigitSum += num[i] - '0';
            freq[num[i] - '0']++;
        }

        if(totalDigitSum % 2 != 0) {
            return 0;
        }

        //Precomputing factorial
        vector<long long> fact(n+1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % M;
        }

        //Precomputing FermatFactorial (inverse factorial --- (1/x)%M)
        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], M-2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M;

        int digit = 0;
        int evenIndexDigitsCount = 0;
        int currSum = 0;
        vector<vector<vector<int>>> t(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));
        return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact, t);

    }
};



/****************************************************************** Java **********************************************************/
// Approach-1 (Brute Force)
// T.C : O(n * n!)
// S.C : O(n * n!), storing all permutations in set
class Solution {
    public int countBalancedPermutations(String num) {
        char[] chars = num.toCharArray();
        Arrays.sort(chars); // Sorting helps next_permutation to find all permutations, so we need to start from smallest (hence sorted)
        Set<String> seen = new HashSet<>();
        int count = 0;

        do {
            String s = new String(chars);
            if (seen.contains(s))
                continue;
            seen.add(s);
            int evenSum = 0, oddSum = 0;
            for (int i = 0; i < chars.length; ++i) {
                int digit = chars[i] - '0';
                if (i % 2 == 0) evenSum += digit;
                else oddSum += digit;
            }
            if (evenSum == oddSum) {
                count++;
            }
        } while (nextPermutation(chars));

        return count;
    }

    // Helper method for next permutation
    private boolean nextPermutation(char[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i < 0) return false;
        int j = arr.length - 1;
        while (arr[j] <= arr[i]) j--;
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        reverse(arr, i + 1, arr.length - 1);
        return true;
    }

    private void reverse(char[] arr, int start, int end) {
        while (start < end) {
            char tmp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = tmp;
        }
    }
}


// Approach-2 (Recursion + Memoization)
// T.C : O(10 * n^2 * Sum)
// S.C : O(10 ^ n * Sum)
class Solution {
    int n;
    int totalDigitSum;
    int M = (int) 1e9 + 7;
    long totalPermPossible = 0;

    // Binary exponentiation
    int findPower(long a, long b) {
        if (b == 0) {
            return 1;
        }

        long half = findPower(a, b / 2);
        long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return (int) result;
    }

    int solve(int digit, int evenIndexDigitsCount, int currSum,
              int[] freq, long[] fermatFact,
              int[][][] t) {
        if (digit == 10) {
            if (currSum == totalDigitSum / 2 && evenIndexDigitsCount == (n + 1) / 2) {
                return (int) totalPermPossible;
            }
            return 0;
        }

        if (t[digit][evenIndexDigitsCount][currSum] != -1) {
            return t[digit][evenIndexDigitsCount][currSum];
        }

        long ways = 0;

        for (int count = 0; count <= Math.min(freq[digit], (n + 1) / 2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount = freq[digit] - count;

            long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % M;

            long val = solve(digit + 1, evenIndexDigitsCount + evenPosCount, currSum + digit * count, freq, fermatFact, t);

            ways = (ways + (val * div) % M) % M;
        }

        return t[digit][evenIndexDigitsCount][currSum] = (int) ways;
    }

    public int countBalancedPermutations(String num) {
        n = num.length();
        totalDigitSum = 0;

        int[] freq = new int[10];
        for (int i = 0; i < n; i++) {
            totalDigitSum += num.charAt(i) - '0';
            freq[num.charAt(i) - '0']++;
        }

        if (totalDigitSum % 2 != 0) {
            return 0;
        }

        // Precomputing factorial
        long[] fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }

        // Precomputing Fermat factorial (inverse factorial)
        long[] fermatFact = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], M - 2);
        }

        totalPermPossible = (fact[(n + 1) / 2] * fact[n / 2]) % M;

        int[][][] t = new int[10][(n + 1) / 2 + 1][totalDigitSum + 1];
        for (int[][] arr2D : t)
            for (int[] arr1D : arr2D)
                Arrays.fill(arr1D, -1);

        return solve(0, 0, 0, freq, fermatFact, t);
    }
}
