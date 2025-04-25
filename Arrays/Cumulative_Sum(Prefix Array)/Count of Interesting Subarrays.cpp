/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : 
    Company Tags                   : Will update soon
    Leetcode Link                  : https://leetcode.com/problems/count-of-interesting-subarrays/description/
    Similar Problem Leetcode - 974 : https://www.youtube.com/watch?v=7Xeorb721LQ
*/


/************************************************************ C++ *****************************************************/
//Approach (Using same concept as Leetcode - 974) - cumulative sum and modulo property
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        unordered_map<int, long long> mp; //remainder -> count
        long long sum = 0; //sum will be equal to cnt of those elements % m == k

        long long result = 0;

        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % m == k)
                sum += 1;

            int r1 = sum%m;

            int r2 = (r1 - k + m) % m;

            result += mp[r2];
            mp[r1]++;
        }

        return result;

    }
};


/************************************************************ JAVA *****************************************************/
//Approach (Using same concept as Leetcode - 974) - cumulative sum and modulo property
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int n = nums.size();
        Map<Integer, Long> mp = new HashMap<>(); // remainder -> count
        long sum = 0;
        long result = 0;

        mp.put(0, 1L);

        for (int i = 0; i < n; i++) {
            if (nums.get(i) % modulo == k) {
                sum += 1;
            }

            int r1 = (int)(sum % modulo);
            int r2 = (r1 - k + modulo) % modulo;

            result += mp.getOrDefault(r2, 0L);
            mp.put(r1, mp.getOrDefault(r1, 0L) + 1);
        }

        return result;
    }
}
