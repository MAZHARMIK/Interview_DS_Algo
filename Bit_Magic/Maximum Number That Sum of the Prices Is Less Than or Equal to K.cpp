/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=D5yhQ-bqw9E
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1
//T.C : O(k * log(num)) - TLE
//S.C : O(1)
class Solution {
public:
    typedef long long ll;
    
    ll getPrice(ll num, int x) {
        ll price = 0;
        
        while(num) {
            int xth_bit = ((1 << (x-1)) & num);
            
            if(xth_bit > 0) {
                price++;
            }
            
            num = (num >> x);
        }
        
        return price;
        
    }
    
    long long findMaximumNumber(long long k, int x) {
        int num = 1;
        int sum = 0;
        
        while(true) {
            int price = getPrice(num, x);
            if(sum+price <= k) {
                sum += price;
            } else
                break;
            num++;
        }
        
        return num-1;
    }
};


//Approach-2
//T.C : O(log(k) * log(num)) - Accepted
//S.C : O(1)
class Solution {
public:
    typedef long long ll;
    vector<ll> bitCount;

    void getBits(ll number) {
        if (number == 0)
            return;
        
        if (number == 1) {
            bitCount[0]++;
            return;
        }
        
        if (number == 2) {
            bitCount[0]++;
            bitCount[1]++;
            return;
        }

        ll bitLen          = log2(number);
        ll nearestPowerTwo = (1ll << bitLen);
        bitCount[bitLen]  += (number - nearestPowerTwo + 1);

        for (ll i = 0; i < bitLen; i++) {
            bitCount[i] += (nearestPowerTwo / 2);
        }

        number = number - nearestPowerTwo;
        getBits(number);
    }

    ll findMaximumNumber(ll threshold, int divisor) {
        ll low = 0, high = 1e15;
        
        ll result = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            bitCount = vector<ll>(65, 0);
            
            getBits(mid);

            ll accumulatedCount = 0;
            
            for (ll i = 0; i < log2(mid)+1; i++) {
                if ((i + 1) % divisor == 0) 
                    accumulatedCount += bitCount[i];
            }

            if (accumulatedCount <= threshold) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};


/*************************************************************** JAVA ***************************************************************/
//Approach-1
//T.C : O(k * log(num)) - TLE
//S.C : O(1)
public class Solution {
    // Define a long long type in Java
    static class LL {
        long value;
        
        LL(long value) {
            this.value = value;
        }
    }

    public static long getPrice(long num, int x) {
        long price = 0;

        while (num != 0) {
            int xthBit = (int) ((1L << (x - 1)) & num);

            if (xthBit > 0) {
                price++;
            }

            num = num >> x;
        }

        return price;
    }

    public static long findMaximumNumber(long k, int x) {
        int num = 1;
        int sum = 0;

        while (true) {
            int price = (int) getPrice(num, x);
            if (sum + price <= k) {
                sum += price;
            } else {
                break;
            }
            num++;
        }

        return num - 1;
    }
}



//Approach-2
//T.C : O(log(k) * log(num)) - ACCEPTED
//S.C : O(1)
public class Solution {
    // Define a long long type in Java
    static class LL {
        long value;
        
        LL(long value) {
            this.value = value;
        }
    }

    // Equivalent of vector<ll> bitCount
    static long[] bitCount;

    public static void getBits(long number) {
        if (number == 0)
            return;

        if (number == 1) {
            bitCount[0]++;
            return;
        }

        if (number == 2) {
            bitCount[0]++;
            bitCount[1]++;
            return;
        }

        long bitLen = (long) (Math.log(number) / Math.log(2));
        long nearestPowerTwo = (1L << bitLen);
        bitCount[(int) bitLen] += (number - nearestPowerTwo + 1);

        for (long i = 0; i < bitLen; i++) {
            bitCount[(int) i] += (nearestPowerTwo / 2);
        }

        number = number - nearestPowerTwo;
        getBits(number);
    }

    public static long findMaximumNumber(long threshold, int divisor) {
        long low = 0, high = (long) 1e15;

        long result = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;

            // Equivalent of initializing bitCount in C++
            bitCount = new long[65];
            Arrays.fill(bitCount, 0);

            getBits(mid);

            long accumulatedCount = 0;

            for (long i = 0; i < (long) (Math.log(mid) / Math.log(2)) + 1; i++) {
                if ((i + 1) % divisor == 0)
                    accumulatedCount += bitCount[(int) i];
            }

            if (accumulatedCount <= threshold) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
}
