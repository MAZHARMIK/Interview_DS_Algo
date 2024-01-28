/*
  MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-SWrz90jCUM
  Company Tags                : Amazon, Meta
  Leetcode Qn Link            : https://leetcode.com/problems/subarray-sum-equals-k/
*/

/**************************************************************** C++ ***************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int sum = 0;
        map<int, int> mp;
        mp.insert({0,1});
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            if(mp.count(sum-k))
                result += mp[sum-k];
            
            mp[sum]++;
        }
        return result;
    }
};



/**************************************************************** JAVA ***************************************************************/
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int result = 0;
        int sum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (map.containsKey(sum - k))
                result += map.get(sum - k);

            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        return result;
    }
}
