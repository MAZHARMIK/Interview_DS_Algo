/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO LINK : https://www.youtube.com/watch?v=M-MMjMe0P0U
    Company Tags          : LiveRamp
    Leetcode Link         : https://leetcode.com/problems/longest-harmonious-subsequence/
*/



/************************************************************ C++ *****************************************************/
//Approach (Using map and counting)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        int result = 0; //to store maximum subsequence length

        for(int &num : nums) {
            mp[num]++;
        }

        for(int &num : nums) {
            int minNum = num;
            int maxNum = num+1;

            if(mp.count(maxNum)) {
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Using map and counting)
//T.C : O(n)
//S.C : O(n)
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int result = 0;

        // Count frequencies
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        // Check for harmonious subsequences
        for (int num : nums) {
            int minNum = num;
            int maxNum = num + 1;

            if (map.containsKey(maxNum)) {
                result = Math.max(result, map.get(minNum) + map.get(maxNum));
            }
        }

        return result;
    }
}
