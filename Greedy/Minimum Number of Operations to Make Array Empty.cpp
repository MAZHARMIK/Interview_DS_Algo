/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lkPNh2M1lUs
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
*/


/******************************************************************* C++ *********************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int result = 0;
        
        for(auto &it : mp) {
            int freq = it.second;
            
            if(freq == 1) { //we can only remove equal elements
                return -1;
            }
            
            result += ceil((double)freq/3);
        }
        
        return result;
    }
};


/******************************************************************* JAVA *********************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;

        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        int result = 0;

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int freq = entry.getValue();

            if (freq == 1) {
                // we can only remove equal elements
                return -1;
            }

            result += Math.ceil((double) freq / 3);
        }

        return result;
    }
}
