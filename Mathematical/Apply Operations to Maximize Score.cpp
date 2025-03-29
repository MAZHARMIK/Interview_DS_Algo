/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/apply-operations-to-maximize-score/description/
*/


/****************************************************** C++ **************************************************************/
//Approach (Using Primes, BinaryExponentiation, NextGreater, PrevGreater, Sorting)
//T.C : O(mloglogm + nlogm + nlogn + nlogk)
//S.C : O(m+n), where m = maxElement, n = nums.size()
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long findPower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) % MOD;
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    vector<int> findPrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        int maxElement = *max_element(begin(nums), end(nums));
        vector<int> primes = getPrimes(maxElement); //O(mloglogm)

        for(int i = 0; i < n; i++) { //O(n * log(m))
            int num = nums[i];

            for(int prime : primes) {
                if(prime*prime > num) {
                    break;
                }

                if(num % prime != 0) {
                    continue;
                }

                primeScores[i]++;
                while(num%prime == 0) {
                    num /= prime;
                }
            }
            if(num > 1) { //example : 15 : 3, 5
                primeScores[i]++;
            }
        }

        return primeScores;
    }

    vector<int> findNextGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> nextGreator(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }

            nextGreator[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nextGreator;
    }

    vector<int> findPrevGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> prevGreator(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }

            prevGreator[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prevGreator;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = findPrimeScores(nums); //O(mloglogm + n*log(m))
        vector<int> nextGreater = findNextGreater(primeScores); //O(n)
        vector<int> prevGreater = findPrevGreater(primeScores); //O(n)

        int n = nums.size();
        vector<long long> subarrays(n, 0);

        for(int i = 0; i < n; i++) { //O(n)
            subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
        }

        vector<pair<int, int>> sortedNums(n);
        for(int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }

        sort(begin(sortedNums), end(sortedNums), greater<>()); //O(nlogn)

        long long score = 1;

        int idx = 0; //start from largest element greedily
        while(k > 0) { //O(k * log(operations))
            auto [num, i] = sortedNums[idx];

            long long operations = min((long long)k, subarrays[i]);

            score = (score * findPower(num, operations)) % MOD;

            k  = (k - operations);
            idx++;
        }

        return score;
        
    }
};


/****************************************************** Java **************************************************************/
// Approach (Using Primes, BinaryExponentiation, NextGreater, PrevGreater, Sorting)
// T.C : O(m log log m + n log m + n log n + n log k)
// S.C : O(m + n), where m = maxElement, n = nums.size()
class Solution {
    final int MOD = (int) 1e9 + 7;

    private long findPower(long a, long b) {
        if (b == 0) return 1;
        long half = findPower(a, b / 2);
        long result = (half * half) % MOD;
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result;
    }

    private List<Integer> getPrimes(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        List<Integer> primes = new ArrayList<>();

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }

        return primes;
    }

    private int[] findPrimeScores(List<Integer> nums) {
        int n = nums.size();
        int[] primeScores = new int[n];

        int maxElement = Collections.max(nums);
        List<Integer> primes = getPrimes(maxElement);

        for (int i = 0; i < n; i++) {
            int num = nums.get(i);

            for (int prime : primes) {
                if (prime * prime > num) break;

                if (num % prime != 0) continue;

                primeScores[i]++;
                while (num % prime == 0) {
                    num /= prime;
                }
            }
            if (num > 1) {
                primeScores[i]++;
            }
        }

        return primeScores;
    }

    private int[] findNextGreater(int[] primeScores) {
        int n = primeScores.length;
        int[] nextGreater = new int[n];
        Arrays.fill(nextGreater, n);
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && primeScores[stack.peek()] <= primeScores[i]) {
                stack.pop();
            }
            nextGreater[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }

        return nextGreater;
    }

    private int[] findPrevGreater(int[] primeScores) {
        int n = primeScores.length;
        int[] prevGreater = new int[n];
        Arrays.fill(prevGreater, -1);
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && primeScores[stack.peek()] < primeScores[i]) {
                stack.pop();
            }
            prevGreater[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        return prevGreater;
    }

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        int[] primeScores = findPrimeScores(nums);
        int[] nextGreater = findNextGreater(primeScores);
        int[] prevGreater = findPrevGreater(primeScores);

        long[] subarrays = new long[n];
        for (int i = 0; i < n; i++) {
            subarrays[i] = (long) (nextGreater[i] - i) * (i - prevGreater[i]);
        }

        List<int[]> sortedNums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sortedNums.add(new int[]{nums.get(i), i});
        }

        sortedNums.sort((a, b) -> b[0] - a[0]); // descending

        long score = 1;
        int idx = 0;

        while (k > 0) {
            int num = sortedNums.get(idx)[0];
            int i = sortedNums.get(idx)[1];

            long operations = Math.min((long) k, subarrays[i]);
            score = (score * findPower(num, operations)) % MOD;

            k -= operations;
            idx++;
        }

        return (int) score;
    }
}
