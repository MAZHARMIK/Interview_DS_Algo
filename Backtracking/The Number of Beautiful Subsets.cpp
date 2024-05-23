/*     Scroll down to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RoEzdG1bB9s
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/the-number-of-beautiful-subsets/
*/

/********************************************************************** C++ **********************************************************************/
//Simple backtracking just like subsets
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:

    int result;
    int K;
    void dfs(vector<int> &nums, int idx, unordered_map<int, int> &mp) {

        if(idx == nums.size()) {
            result++;
            return;
        }

        //not_take
        dfs(nums, idx+1, mp);
        
        //checking if we can take it or not
        if(!mp[nums[idx] - K] && !mp[nums[idx] + K]) {
                mp[nums[idx]]++;
                dfs(nums, idx + 1, mp);
                mp[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        result = 0;
        K = k;

        unordered_map<int, int> mp;
 
        dfs(nums, 0, mp);

        return result - 1; //-1 because we don't want to count empty subset in result
    }
};


/********************************************************************** JAVA **********************************************************************/
//Simple backtracking just like subsets
//T.C : O(2^n)
//S.C : O(n)
public class Solution {
    private int result;
    private int K;

    private void dfs(int[] nums, int idx, Map<Integer, Integer> mp) {
        if (idx == nums.length) {
            result++;
            return;
        }

        // not_take
        dfs(nums, idx + 1, mp);

        // checking if we can take it or not
        if (!mp.containsKey(nums[idx] - K) && !mp.containsKey(nums[idx] + K)) {
            mp.put(nums[idx], mp.getOrDefault(nums[idx], 0) + 1);
            dfs(nums, idx + 1, mp);
            mp.put(nums[idx], mp.get(nums[idx]) - 1);

            // Remove the key if its count drops to 0 to mimic the C++ erase behavior
            if (mp.get(nums[idx]) == 0) {
                mp.remove(nums[idx]);
            }
        }
    }

    public int beautifulSubsets(int[] nums, int k) {
        result = 0;
        K = k;
        Map<Integer, Integer> mp = new HashMap<>();
        dfs(nums, 0, mp);
        return result - 1; // -1 because we don't want to count the empty subset in the result
    }
}


