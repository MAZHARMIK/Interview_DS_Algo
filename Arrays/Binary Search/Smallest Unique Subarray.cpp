/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TeuppWyT2AQ
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/smallest-unique-subarray
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search on answer + Sliding Window + Rolling Hash)
//T.C : O(n*logn)
//S.C : O(n) for map
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    // Binary exponentiation
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp;

        ll p = findPower(base, size-1); //O(log(size))

        int i = 0;
        int j = 0;

        while(j < n) { //O(n)
            hash = (hash * base + nums[j]) % MOD;

            if(j-i+1 < size) {
                j++;
            } else {
                mp[hash]++;

                hash = (hash - (p * nums[i])%MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for(auto &it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;

    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1;
        int r = n;

        int result = n;

        while(l <= r) { //log(n)
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Binary search on answer + Sliding Window + Rolling Hash)
//T.C : O(n*logn)
//S.C : O(n) for map
class Solution {
    private static final long MOD = 1_000_000_007L;

    // Binary exponentiation
    private long findPower(long a, long exp) {
        if (exp == 0) {
            return 1;
        }

        long half = findPower(a, exp / 2);
        long result = (half * half) % MOD;
        if (exp % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    private boolean check(int[] nums, int size, long base) {
        int n = nums.length;

        long hash = 0;
        Map<Long, Integer> mp = new HashMap<>();

        long p = findPower(base % MOD, size - 1); // O(log(size))

        int i = 0;
        int j = 0;

        while (j < n) { // O(n)
            hash = (hash * base + nums[j]) % MOD;

            if (j - i + 1 < size) {
                j++;
            } else {
                mp.put(hash, mp.getOrDefault(hash, 0) + 1);

                hash = (hash - (p * nums[i]) % MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for (int count : mp.values()) {
            if (count == 1) {
                return true;
            }
        }

        return false;
    }

    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        long base = Arrays.stream(nums).max().getAsInt() + 1L;

        int l = 1;
        int r = n;

        int result = n;

        while (l <= r) { // O(log n)
            int mid = l + (r - l) / 2;

            if (check(nums, mid, base)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
}
