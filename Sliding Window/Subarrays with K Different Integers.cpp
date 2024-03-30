/* Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Approach-1 -- https://www.youtube.com/watch?v=uJJSGxfzix8
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/subarrays-with-k-different-integers/
*/

/*********************************************************************** C++ ***********************************************************/
//Approach-1 (Standard Sliding Window twice - A very good Pattern of Sliding Window Problems)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    
    //Total count of subarrays having <= k distict elements
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int n = nums.size();
        int i = 0; 
        int j = 0;
        
        int count = 0;
        
        while(j < n) {
            
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                //shrink the window
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            count += (j-i+1); //ending at j
            j++;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};




/*********************************************************************** JAVA ***********************************************************/
//Approach-1 (Standard Sliding Window twice - A very good Pattern of Sliding Window Problems)
//T.C : O(n)
//S.C : O(n)
class Solution {
    
    // Total count of subarrays having <= k distinct elements
    public int slidingWindow(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        int n = nums.length;
        int i = 0; 
        int j = 0;
        
        int count = 0;
        
        while(j < n) {
            
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            
            while(mp.size() > k) {
                // Shrink the window
                mp.put(nums[i], mp.get(nums[i]) - 1);
                if(mp.get(nums[i]) == 0) {
                    mp.remove(nums[i]);
                }
                i++;
            }
            
            count += (j - i + 1); // Ending at j
            j++;
        }
        
        return count;
    }
    
    public int subarraysWithKDistinct(int[] nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
}
