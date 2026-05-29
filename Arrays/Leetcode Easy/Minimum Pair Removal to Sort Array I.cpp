/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kwrBFKA0Huo
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i
*/


/*********************************************************** C++ **************************************************/
//Approach (Simple simulation)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int minSum = INT_MAX;
        int index = -1;

        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < minSum) {
                index = i;
                minSum = nums[i] + nums[i+1];
            }
        }

        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(!is_sorted(begin(nums), end(nums))) {
            int index = minPairSum(nums);

            nums[index] = nums[index] + nums[index+1];

            nums.erase(begin(nums) + index + 1);

            operations++;
        }

        return operations;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Simple simulation)
//T.C : O(n^2)
//S.C : O(1)
class Solution {

    private int minPairSum(List<Integer> nums) {
        int minSum = Integer.MAX_VALUE;
        int index = -1;

        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums.get(i) + nums.get(i + 1);
            if (sum < minSum) {
                minSum = sum;
                index = i;
            }
        }

        return index;
    }

    private boolean isSorted(List<Integer> nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.get(i) > nums.get(i + 1)) {
                return false;
            }
        }
        return true;
    }

    public int minimumPairRemoval(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }

        int operations = 0;

        while (!isSorted(list)) {
            int index = minPairSum(list);

            int merged = list.get(index) + list.get(index + 1);
            list.set(index, merged);
            list.remove(index + 1);

            operations++;
        }

        return operations;
    }
}
