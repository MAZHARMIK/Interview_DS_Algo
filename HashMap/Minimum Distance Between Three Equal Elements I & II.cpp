/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Qio1gMSEzG8
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i
                                  https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii
*/


/************************************************************ C++ *****************************************************/
//You can do brute force for all three indices for a number.

//Approach - Optimal : Using map forstoring indices and checking for 3 indices for a number 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for(int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];
                int siz = vec.size();

                int i = vec[siz-3];
                result = min(result, k-i);
            }
        }

        return result >= INT_MAX ? -1 : 2*result;
    }
};



/************************************************************ JAVA *****************************************************/
//You can do brute force for all three indices for a number.

//Approach - Optimal : Using map forstoring indices and checking for 3 indices for a number 
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;

        Map<Integer, List<Integer>> mp = new HashMap<>();
        int result = n;

        for (int k = 0; k < n; k++) {
            mp.putIfAbsent(nums[k], new ArrayList<>());
            mp.get(nums[k]).add(k);

            if (mp.get(nums[k]).size() >= 3) {
                List<Integer> list = mp.get(nums[k]);
                int siz = list.size();
                int i = list.get(siz - 3);
                result = Math.min(result, k - i);
            }
        }

        return result >= n ? -1 : 2 * result;
    }
}
