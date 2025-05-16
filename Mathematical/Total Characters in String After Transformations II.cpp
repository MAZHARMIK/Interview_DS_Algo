/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=MGu9Zr5RFtg
    Prerequisite Video (Matrix Exponentiation) : https://www.youtube.com/watch?v=gX8KaRlkoN0
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/total-characters-in-string-after-transformations-ii
    
*/


/****************************************************** C++ **************************************************************/
//Approach - Using Matrix Exponentiation
//T.C : O(n + log(t))
//S.C : O(26*26) ~ O(1)
class Solution {
    typedef vector<vector<int>> Matrix;
    int MOD = 1e9 + 7;

    Matrix matrixMultiplication(const Matrix& A, const Matrix& B) {
        Matrix result(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }

    Matrix matrixExponentiation(const Matrix& base, int exponent) {

        if (exponent == 0) {
            Matrix identity(26, vector<int>(26, 0));
            for (int i = 0; i < 26; ++i)
                identity[i][i] = 1;
            return identity;
        }

        Matrix half   = matrixExponentiation(base, exponent / 2);
        Matrix result = matrixMultiplication(half, half);

        if (exponent % 2 == 1)
            result = matrixMultiplication(result, base);

        return result;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        Matrix T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int add = 1; add <= nums[i]; ++add)
                T[(i + add) % 26][i]++;
        }

        Matrix result = matrixExponentiation(T, t);

        vector<int> updated_freq(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)
                updated_freq[i] = (updated_freq[i] + (1LL * result[i][j] * freq[j]) % MOD) % MOD;
        }

        int resultLength = 0;
        for (int i = 0; i < 26; ++i)
            resultLength = (resultLength + updated_freq[i]) % MOD;

        return resultLength;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Using Matrix Exponentiation
//T.C : O(n + log(t))
//S.C : O(26*26) ~ O(1)
public class Solution {
    private static final int MOD = 1_000_000_007;
    private static final int SIZE = 26;

    // Matrix multiplication
    private List<List<Integer>> matrixMultiplication(List<List<Integer>> A, List<List<Integer>> B) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < SIZE; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(SIZE, 0));
            result.add(row);
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                long sum = 0;
                for (int k = 0; k < SIZE; ++k) {
                    sum = (sum + 1L * A.get(i).get(k) * B.get(k).get(j)) % MOD;
                }
                result.get(i).set(j, (int) sum);
            }
        }
        return result;
    }

    // Matrix exponentiation
    private List<List<Integer>> matrixExponentiation(List<List<Integer>> base, int exponent) {
        // Identity matrix
        List<List<Integer>> identity = new ArrayList<>();
        for (int i = 0; i < SIZE; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(SIZE, 0));
            row.set(i, 1);
            identity.add(row);
        }

        if (exponent == 0)
            return identity;

        List<List<Integer>> half = matrixExponentiation(base, exponent / 2);
        List<List<Integer>> result = matrixMultiplication(half, half);

        if (exponent % 2 == 1)
            result = matrixMultiplication(result, base);

        return result;
    }

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        int[] freq = new int[SIZE];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Build transformation matrix T
        List<List<Integer>> T = new ArrayList<>();
        for (int i = 0; i < SIZE; i++) {
            T.add(new ArrayList<>(Collections.nCopies(SIZE, 0)));
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int add = 1; add <= nums.get(i); ++add) {
                int newIndex = (i + add) % SIZE;
                T.get(newIndex).set(i, T.get(newIndex).get(i) + 1);
            }
        }

        // Matrix exponentiation
        List<List<Integer>> result = matrixExponentiation(T, t);

        // Apply transformation to frequency vector
        int[] updatedFreq = new int[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            long value = 0;
            for (int j = 0; j < SIZE; ++j) {
                value = (value + 1L * result.get(i).get(j) * freq[j]) % MOD;
            }
            updatedFreq[i] = (int) value;
        }

        // Compute final length
        int resultLength = 0;
        for (int val : updatedFreq) {
            resultLength = (resultLength + val) % MOD;
        }

        return resultLength;
    }
}
