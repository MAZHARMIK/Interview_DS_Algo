/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5jpCEfRI1sM
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/make-sum-divisible-by-p/description/
*/

/**************************************************************** C++ ****************************************************************/
//Approach  (Using prefix sum modulo and storing in hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int SUM = 0;

        //(a+b)%p = (a%p + b%p) % p
        for(int &num : nums) {
            SUM = (SUM + num) % p;
        }

        int target = SUM%p;

        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> mp; //prev sum%p ko store karega

        int curr = 0;
        mp[0] = -1;

        int result = n;
        for(int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if(mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);
            }

            mp[curr] = j;
        }

        return result == n ? -1 : result;

    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach  (Using prefix sum modulo and storing in hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int sum = 0;

        // Calculate the sum of all elements and take % p
        for (int num : nums) {
            sum = (sum + num) % p;
        }

        int target = sum % p;
        
        // If sum is already divisible by p, no need to remove any subarray
        if (target == 0) {
            return 0;
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);  // Initialize with remainder 0 at index -1
        
        int curr = 0;
        int result = n;
        
        // Traverse through the array
        for (int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;

            // Calculate the remainder needed to achieve the target
            int remain = (curr - target + p) % p;
            
            // If the required remainder exists in the map, update the result
            if (map.containsKey(remain)) {
                result = Math.min(result, j - map.get(remain));
            }
            
            // Store the current remainder with its index
            map.put(curr, j);
        }

        return result == n ? -1 : result;
    }
}
