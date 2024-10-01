/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
*/


/************************************************************ C++ ************************************************/
//Approach-(simple remainder maths)
//T.C : O(n)
//S.C : O(k)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0); //O(K)
        //mp[r] = x
        //remainder r has frequency x

        for(int &num : arr) {
            int rem = (num%k + k) % k; //handling negative remainders
            mp[rem]++;
        }

        if(mp[0] % 2 != 0) {
            return false;
        }

        for(int rem = 1; rem <= k/2; rem++) {
            int counterHalf = k - rem;
            if(mp[counterHalf] != mp[rem]) {
                return false;
            }
        }

        return true;
    }
};


/************************************************************ JAVA ************************************************/
//Approach-(simple remainder maths)
//T.C : O(n)
//S.C : O(k)
class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] mp = new int[k];  // Array to store remainders frequency

        // Calculate the remainder frequencies
        for (int num : arr) {
            int rem = (num % k + k) % k;  // Handle negative remainders
            mp[rem]++;
        }

        // Check if the frequency of numbers with 0 remainder is even
        if (mp[0] % 2 != 0) {
            return false;
        }

        // Check if each remainder has a complement remainder with matching frequency
        for (int rem = 1; rem <= k / 2; rem++) {
            int counterHalf = k - rem;
            if (mp[counterHalf] != mp[rem]) {
                return false;
            }
        }

        return true;
    }
}
