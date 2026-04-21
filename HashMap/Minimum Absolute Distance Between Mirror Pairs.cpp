/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fnY6t8bXVNQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs
*/


/************************************************************ C++ *****************************************************/
//Approach - Store reverses in map - iterate and find
//T.C : O(n * log(10(num)))
//S.C : O(n)
class Solution {
public:
    int getReverse(int n) {
        int rev = 0;

        while(n > 0) {
            int rem = n%10;

            rev = rev*10 + rem;

            n /= 10;
        }

        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; //reversed -> idx

        int result = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(mp.count(nums[i])) {
                result = min(result, i - mp[nums[i]]);
            }

            mp[getReverse(nums[i])] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach - Store reverses in map - iterate and find
//T.C : O(n * log(10(num)))
//S.C : O(n)
import java.util.*;

class Solution {

    // O(log10(n))
    public int getReverse(int n) {
        int rev = 0;

        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }

        return rev;
    }

    public int minMirrorPairDistance(int[] nums) {
        int n = nums.length;

        HashMap<Integer, Integer> mp = new HashMap<>(); // reversed -> index
        int result = Integer.MAX_VALUE;

        // T.C : O(n * log10(num))
        for (int i = 0; i < n; i++) {

            if (mp.containsKey(nums[i])) {
                result = Math.min(result, i - mp.get(nums[i]));
            }

            mp.put(getReverse(nums[i]), i);
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
