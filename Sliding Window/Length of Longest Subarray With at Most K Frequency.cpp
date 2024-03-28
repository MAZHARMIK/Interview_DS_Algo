/*     Scroll down to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=txSMzRMREKA
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
*/

/*********************************************************************** C++ **********************************************************/
//Approach-1 (With Nested Loop - Classic Sliding Window Template)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        while(j < n) {
            
            mp[nums[j]]++;
            
            while(i < j && mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};



//Approach-2 (Without nested loop)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        int culprit = 0;
        
        while(j < n) {
            
            mp[nums[j]]++;
            if(mp[nums[j]] == k+1) {
                culprit++;
            }
            
            if(culprit > 0) {
                mp[nums[i]]--;
                if(mp[nums[i]] == k) {
                    culprit--;
                }
                i++;
            }
            
            if(culprit == 0) {
                result = max(result, j-i+1);
            }
            j++;
        }
        
        return result;
    }
};


/*********************************************************************** JAVA **********************************************************/
//Approach-1 (With Nested Loop - Classic Sliding Window Template)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        
        Map<Integer, Integer> map = new HashMap<>();
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        while(j < n) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            
            while(i < j && map.getOrDefault(nums[j], 0) > k) {
                map.put(nums[i], map.get(nums[i]) - 1);
                if(map.get(nums[i]) == 0)
                    map.remove(nums[i]);
                i++;
            }
            
            result = Math.max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
}

//Approach-2 (Without nested loop)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        
        int i = 0;
        int j = 0;
        int result = 0;
        
        int culprit = 0;
        
        while(j < n) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            
            if(map.get(nums[j]) == k + 1) {
                culprit++;
            }
            
            if(culprit > 0) {
                map.put(nums[i], map.get(nums[i]) - 1);
                if(map.get(nums[i]) == k) {
                    culprit--;
                }
                i++;
            }
            
            if(culprit == 0) {
                result = Math.max(result, j - i + 1);
            }
            j++;
        }
        
        return result;
    }
}
