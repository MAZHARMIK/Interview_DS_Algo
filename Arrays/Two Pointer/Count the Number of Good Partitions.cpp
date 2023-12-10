/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fyyjpElDeuY
    Company Tags                : I will update soon
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-good-partitions/
*/

/************************************************************ C++ ************************************************************/
//Approach (Using simple 2 Pointer)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last_index; //number, last index

        for (int i = 0; i < n; ++i) {
            last_index[nums[i]] = i;
        }

        int i = 0;
        int j = max(0, last_index[nums[0]]);

        int result = 1;
        while(i < n) {
            if(i > j) { //we found one partition
                result = (result*2)%M;
            }

            j = max(j, last_index[nums[i]]);
            i++;
        }

        return result;
    }
};



/************************************************************ C++ ************************************************************/
//Approach (Using simple 2 Pointer)
//T.C : O(n)
//S.C : O(n)
import java.util.HashMap;
import java.util.Map;

class Solution {
    int M = 1000000007;

    public int numberOfGoodPartitions(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> last_index = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            last_index.put(nums[i], i);
        }

        int i = 0;
        int j = Math.max(0, last_index.get(nums[0]));

        int result = 1;
        while (i < n) {
            if (i > j) {
                result = (int) ((result * 2L) % M);
            }

            j = Math.max(j, last_index.get(nums[i]));
            i++;
        }

        return result;
    }
}
