/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-complete-subarrays-in-an-array/
*/


/********************************************************************** C++ **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums), end(nums));

        int c = st.size();

        int i = 0;
        int j = 0;
        int res = 0;

        unordered_map<int, int> mp;
        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() == c) {
                res += (n-j);

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return res;
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(n)
import java.util.*;

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int n = nums.length;
        Set<Integer> uniqueSet = new HashSet<>();
        for (int num : nums) {
            uniqueSet.add(num);
        }
        
        int totalUnique = uniqueSet.size();
        int res = 0;
        int i = 0;
        
        Map<Integer, Integer> freqMap = new HashMap<>();
        
        for (int j = 0; j < n; j++) {
            freqMap.put(nums[j], freqMap.getOrDefault(nums[j], 0) + 1);
            
            while (freqMap.size() == totalUnique) {
                res += (n - j);
                
                freqMap.put(nums[i], freqMap.get(nums[i]) - 1);
                if (freqMap.get(nums[i]) == 0) {
                    freqMap.remove(nums[i]);
                }
                i++;
            }
        }
        
        return res;
    }
}
