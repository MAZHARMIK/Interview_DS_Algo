/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fwKTSOUvzaE
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/closest-prime-numbers-in-range
*/


//****************************************************** C++ ************************************************************************//
//Approach-1 (Using Sieve Of Eratosthenes)
//T.C : O(Rlog(log(R)) + (R-L))
//S.C : O(R)
class Solution {
public:
    vector<bool> sieveHelper(int right) {
        vector<bool> isPrime(right+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i <= right; i++) {
            if(isPrime[i] == true) {
                for(int j = 2; i*j <= right; j++) {
                    isPrime[i*j] = false;
                }
            }
        }

        return isPrime;
    }


    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveHelper(right);

        vector<int> primes;
        for(int num = left; num <= right; num++) {
            if(isPrime[num] == true) {
                primes.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];

            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};



//Approach-2 (Using Sieve Of Eratosthenes)
//T.C : O((R-L) * sqrt(R))
//S.C : O(R-L)
class Solution {
public:
    bool isPrime(int num) {
        if(num == 1) { //not a prime
            return false;
        }
        for(int div = 2; div*div <= num; div++) {
            if(num % div == 0) {
                return false;
            }
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for(int num = left; num <= right; num++) {
            if(isPrime(num) == true) {
                if(!primes.empty() && num - primes.back() <= 2) {
                    return {primes.back(), num}; //Early return
                }

                primes.push_back(num);
            }
        }


        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};
        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};


//****************************************************** Java ************************************************************************//
//Approach-1 (Using Sieve Of Eratosthenes)
//T.C : O(Rlog(log(R)) + (R-L))
//S.C : O(R)
class Solution {
    private boolean[] sieveHelper(int right) {
        boolean[] isPrime = new boolean[right + 1];
        Arrays.fill(isPrime, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = 2; i * j <= right; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
        return isPrime;
    }

    public int[] closestPrimes(int left, int right) {
        boolean[] isPrime = sieveHelper(right);

        List<Integer> primes = new ArrayList<>();
        for (int num = left; num <= right; num++) {
            if (isPrime[num]) {
                primes.add(num);
            }
        }

        int minDiff = Integer.MAX_VALUE;
        int[] result = {-1, -1};

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes.get(i) - primes.get(i - 1);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = primes.get(i - 1);
                result[1] = primes.get(i);
            }
        }

        return result;
    }
}


//Approach-2 (Using Sieve Of Eratosthenes)
//T.C : O((R-L) * sqrt(R))
//S.C : O(R-L)
class Solution2 {
    private boolean isPrime(int num) {
        if (num == 1) { // not a prime
            return false;
        }
        for (int div = 2; div * div <= num; div++) {
            if (num % div == 0) {
                return false;
            }
        }
        return true;
    }

    public int[] closestPrimes(int left, int right) {
        List<Integer> primes = new ArrayList<>();

        for (int num = left; num <= right; num++) {
            if (isPrime(num)) {
                if (!primes.isEmpty() && num - primes.get(primes.size() - 1) <= 2) {
                    return new int[]{primes.get(primes.size() - 1), num}; // Early return
                }
                primes.add(num);
            }
        }

        int minDiff = Integer.MAX_VALUE;
        int[] result = {-1, -1};
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes.get(i) - primes.get(i - 1);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = primes.get(i - 1);
                result[1] = primes.get(i);
            }
        }

        return result;
    }
}
