/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations
*/


/********************************************************************** C++ **********************************************************************/
//Approach - Greedily sorting and checking each element
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int count = 0;

        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            int minVal = nums[i] - k;

            if(prev < minVal) {
                //nums[i] = nums[i]-k;
                prev = minVal;
                count++;
            } else if(prev < nums[i] + k) {
                //nums[i] = prev+1;
                prev = prev+1;
                count++;
            }
        }

        return count;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach - Greedily sorting and checking each element
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int count = 0;
        int prev = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            int minVal = nums[i] - k;

            if (prev < minVal) {
                // choose nums[i] - k
                prev = minVal;
                count++;
            } else if (prev < nums[i] + k) {
                // choose next available distinct value greater than prev
                prev = prev + 1;
                count++;
            }
        }

        return count;
    }
}
