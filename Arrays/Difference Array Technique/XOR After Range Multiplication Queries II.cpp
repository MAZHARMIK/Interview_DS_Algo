/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=O3rF3W23PNg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/xor-after-range-multiplication-queries-ii
    Pre-Requisite               : https://youtu.be/sG5Lm8vi-2Q?si=RPIFVWUIRCyqCn06 (Difference Array Technique with Jumps)
                                  https://youtu.be/aI10OoSvhUI?si=RIhGnN9Ym7tCgl99 (Square Root Decomposition)
*/


/************************************************************ C++ ************************************************/
//Approach - Using Square Root Decomposition, Difference Array Technique with Jumps + Fermat's Little Theorem + Binary Exponentiation
//T.C : O((N + Q)√N) due to splitting queries by step size,
//S.C : O(N + Q) for storing diff arrays and grouped queries.
class Solution {
public:
    int M = 1e9+7;
    //Binary Exponentiation for Fermat's Little Theorem - > Pow(v ,M-2)
    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); 
        int blockSize = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> smallKMap;

        for(auto &query : queries) {
            int L = query[0];
            int R = query[1];
            int K = query[2];
            int V = query[3];

            if(K >= blockSize) {
                for(int i = L; i<= R; i+=K) {
                    nums[i] = (1LL * nums[i] * V) % M;
                }
            } else { //K < blockSize
                smallKMap[K].push_back(query);
            }
        }

        for(auto& [K, allQueries] : smallKMap) {
            vector<long long> diff(n, 1);

            for(auto& query : allQueries) {
                int L = query[0];
                int R = query[1];
                int V = query[3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R - L)/K;
                int next  = L + (steps+1)*K;

                if(next < n)
                    diff[next] = (diff[next] * power(V, M-2)) % M;
            }

            //Cumulative product
            for(int i = 0; i < n; i++) {
                if(i-K >= 0)
                    diff[i] = (diff[i] * diff[i-K]) % M;
            }

            //Apply diff to nums
            for(int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % M;
            }
        }

        int result = 0;
        for(int &num : nums) {
            result = (result ^ num);
        }

        return result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach - Using Square Root Decomposition, Difference Array Technique with Jumps + Fermat's Little Theorem + Binary Exponentiation
//T.C : O((N + Q)√N) due to splitting queries by step size,
//S.C : O(N + Q) for storing diff arrays and grouped queries.
class Solution {
    int M = (int)1e9 + 7;

    // Iterative Binary Exponentiation
    long power(long a, long b) {
        long result = 1;
        a = a % M;

        while (b > 0) {
            if ((b & 1) == 1) {
                result = (result * a) % M;
            }
            a = (a * a) % M;
            b >>= 1;
        }
        return result;
    }

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int blockSize = (int)Math.ceil(Math.sqrt(n));

        // Map: k -> list of queries
        Map<Integer, List<int[]>> smallKMap = new HashMap<>();

        // Step 1: Process large K directly
        for (int[] query : queries) {
            int L = query[0];
            int R = query[1];
            int K = query[2];
            int V = query[3];

            if (K >= blockSize) {
                for (int i = L; i <= R; i += K) {
                    nums[i] = (int)((1L * nums[i] * V) % M);
                }
            } else {
                smallKMap.computeIfAbsent(K, k -> new ArrayList<>()).add(query);
            }
        }

        // Step 2: Process small K using diff array
        for (Map.Entry<Integer, List<int[]>> entry : smallKMap.entrySet()) {
            int K = entry.getKey();
            List<int[]> allQueries = entry.getValue();

            long[] diff = new long[n];
            Arrays.fill(diff, 1);

            // Apply all queries of this K
            for (int[] query : allQueries) {
                int L = query[0];
                int R = query[1];
                int V = query[3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R - L) / K;
                int next = L + (steps + 1) * K;

                if (next < n) {
                    diff[next] = (diff[next] * power(V, M - 2)) % M;
                }
            }

            // Propagation (jump by K)
            for (int i = 0; i < n; i++) {
                if (i - K >= 0) {
                    diff[i] = (diff[i] * diff[i - K]) % M;
                }
            }

            // Apply to nums
            for (int i = 0; i < n; i++) {
                nums[i] = (int)((1L * nums[i] * diff[i]) % M);
            }
        }

        // Final XOR
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
}
