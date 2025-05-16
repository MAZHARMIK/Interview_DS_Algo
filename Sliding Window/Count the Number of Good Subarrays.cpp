/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bO39iLSqvQY
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-good-subarrays
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        long long result = 0;

        unordered_map<int, int> mp;

        long long pairs = 0;

        while(j < n) {
            pairs += mp[nums[j]]; //isse pehle kitni baar nums[j] dekha hai humne
            mp[nums[j]]++;

            while(pairs >= k) {
                result += (n-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return result;
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long countGood(int[] nums, int k) {
        int n = nums.length;
        int i = 0, j = 0;

        long result = 0;
        long pairs = 0;

        Map<Integer, Integer> map = new HashMap<>();

        while (j < n) {
            pairs += map.getOrDefault(nums[j], 0);
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);

            while (pairs >= k) {
                result += (n - j);
                map.put(nums[i], map.get(nums[i]) - 1);
                pairs -= map.get(nums[i]);
                i++;
            }

            j++;
        }

        return result;
    }
}
